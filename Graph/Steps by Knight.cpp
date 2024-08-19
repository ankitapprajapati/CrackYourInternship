class Solution 
{
    vector<vector<int>> directions = { {-2,-1},{-2,1},{-1,-2},{-1,2},{2,-1},{2,1},{1,-2},{1,2} };

    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    
	    int x = KnightPos[0]-1;
	    int y = KnightPos[1]-1;
	    int targetX = TargetPos[0] - 1;
        int targetY = TargetPos[1] - 1;
        
	    if( x==targetX && y==targetY ) return 0;
	    
	    vector<vector<int>> visited(N,vector<int>(N,0));
	    
	    queue<pair<pair<int,int>,int>> q;
	    q.push( {{x,y},0});
	    visited[x][y]=1;
	    
	    while( !q.empty() ){
	        x=q.front().first.first;
	        y=q.front().first.second;
	        int count = q.front().second;
	        q.pop();
	        
	        for(auto el : directions ){
                int newX = x+el[0];
                int newY = y+el[1];
            
                if( newX>=0 && newY>=0 && newX<N && newY<N && visited[newX][newY]==0 ){
                    if(newX==targetX && newY==targetY ) return count+1;
                    
                    q.push( {{newX,newY},count+1} );
                    visited[newX][newY]=1;
                }
            }
        }
	    return -1;
	}
};