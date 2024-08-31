class Solution {
public:
    int maxi=0;
    unordered_map<int, vector<int>> comp;

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // Build the tree (manager -> subordinates)
        for(int i = 0; i < n; i++){
            int t = manager[i];
            if(t != -1){
                comp[t].push_back(i);
            }
        }
        dfs(headID, informTime, 0);
        return maxi;
    }
    
    void dfs(int s, vector<int>& informTime, int currentTime){
        // Update the maximum time required
        maxi = max(maxi, currentTime);
        // Visit all subordinates of the current employee
        for(auto emp : comp[s]){
            dfs(emp, informTime, currentTime + informTime[s]);
        }
    }
};