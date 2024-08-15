class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        queue<int> q;
        vector<int> visited(V,0);
        vector<int> ans;
        
        q.push(0);
        visited[0]=1;
        
        while( !q.empty() ) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto el:adj[node]){
                if(visited[el]==0){
                    visited[el]=1;
                    q.push(el);
                }
            }
        }
        return ans;
    }
};