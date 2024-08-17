class Solution {
    
    bool dfs( int node, vector<int> adj[], vector<int>& visited, vector<int>& pathVisited ){
        
        visited[node]=1;
        pathVisited[node] =1;
        
        for( auto child : adj[node]){
            if( visited[child]==0 ){
                if( dfs(child,adj,visited,pathVisited) ){
                    return true;
                }
            }else if( pathVisited[child]==1 ){
                return true;
            }
        }
        pathVisited[node]=0;
        return false;
    }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,0);
        vector<int> pathVisited(V,0);
        
        for( int i=0; i<V; i++){
            if(visited[i]==0){
               if( dfs(i,adj,visited,pathVisited) ){
                   return true;
               }
            }
        }
        return false;
    }
};