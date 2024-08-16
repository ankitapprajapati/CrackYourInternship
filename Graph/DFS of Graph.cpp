class Solution {
  public:
  
    void dfs( int node, vector<int>& visited, vector<int>& ans, vector<int> adj[]) {
        visited[node]=1;
        ans.push_back(node);
        
        for( auto el : adj[node] ){
            if(!visited[el]) {
                dfs(el,visited,ans,adj);
            }
        }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited (V,0);
        vector<int> ans;
        dfs(0,visited,ans,adj);
        return ans;
    }
};