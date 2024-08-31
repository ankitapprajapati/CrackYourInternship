class Solution {
    bool check( int start, vector<int>adj[], vector<int>& visited){
	    // Code here
	    
	    queue<int> q;
	    q.push(start);
	    visited[start]=0;
	    
	    while ( !q.empty() ){
	        int preNode = q.front();
	        q.pop();
	        
	        for( auto node : adj[preNode] ){
	           if( visited[node]!=-1 && visited[node]==visited[preNode] ) return false;
	           if ( visited[node]==-1 ){
	               q.push(node);
	               visited[node] = !visited[preNode];
	           }
	        }
	    }
	    
	    return true;
	}
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int> visited ( V,-1);
	    
	    for ( int i=0; i<V; i++){
	        if( visited[i]==-1 ){
	            if( check(i,adj,visited)==false) return false;
	        }
	    }
	    
	    return true;
	}

};