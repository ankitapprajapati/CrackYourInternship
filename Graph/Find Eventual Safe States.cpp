class Solution {
public:
    // Catched memory for faster solution...
    bool cyclic[10000];
    bool visited[10000];

    // dfs function..
    bool helper(vector<vector<int>>& graph, bool cyclic[], bool visited[], int i)
{
        // check if the current node is cyclic, return true
        if(cyclic[i]){
            return true;
        }
        // return false, if node is visited and not cyclic
        if(visited[i]){
            return false;
        }

        // if not visited, check if node is cyclic...
        visited[i] = 1;
        cyclic[i] = 1;
        bool isCyc = false;
        for (int j:graph[i]){
            if(helper(graph, cyclic, visited, j)){
                isCyc = true;
            }
        }
        if(!isCyc){
            cyclic[i] = 0;
        }
        return isCyc;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        memset(cyclic, 0, sizeof(bool));
        memset(visited, 0, sizeof(bool));

        for(int i = 0;i<n;i++){
            helper(graph, cyclic, visited, i);
        }

        // if any node if cyclic, don't add in the answer...
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(!cyclic[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};