   bool cycle(int sr, vector<int> adj[] , vector<int>& visited) {
        // Code here
        queue<pair<int,int>> q;
        q.push( {sr,-1} );
        visited[sr]=1;
        
        while( !q.empty() ){
            int first = q.front().first;
            int second = q.front().second;
            q.pop();
            
            for( auto el : adj[first] ){
                if(el==second) continue;
                
                if( visited[el]==1 ) {
                    return true;
                }else{
                    visited[el]=1;
                    q.push({el,first});
                }
            }
        }
        return false;
    }
    
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,0);
        
        for( int i=0; i<V; i++){
            if(visited[i]==0 && cycle(i,adj,visited)){
                return true;
            }
        }
        return false;
    }