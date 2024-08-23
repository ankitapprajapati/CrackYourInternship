class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,list<int>>adj;
        map<int, int> indegree;
        for(int i=0;i<adjacentPairs.size();i++){
            int u=adjacentPairs[i][0];
            int v=adjacentPairs[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        int node;
        for(auto i:indegree){
            if(i.second==1){
                node=i.first;
                break;
            }
        }
        unordered_map<int,bool>visited;
        vector<int>ans;
        visited[node]=true;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            for(auto i:adj[front]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
        return ans;
    }
};