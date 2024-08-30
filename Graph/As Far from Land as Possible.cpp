class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n,vector<int>(n,-1));
        queue< pair< pair<int,int>,int >> q;

        vector<int> row = {0,0,1,-1};
        vector<int> col = {-1,1,0,0};

        for( int i=0; i<n; i++){
            for( int j=0; j<n; j++ ){
                if( grid[i][j]==1 ) {
                    q.push({{i,j},0});
                    visited[i][j]=0;
                }
            }
        }
        if( q.empty() || q.size()==n*n) return -1;

        int maxi = 0;

        while( !q.empty() ){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dist  = q.front().second;
            q.pop();

            maxi= max(maxi,dist);

            for(int i=0; i<=3; i++){
                int newX = x+row[i];
                int newY = y+col[i];
                if(newX>=0 && newY>=0 && newX<n && newY<n && visited[newX][newY]==-1){
                    visited[newX][newY]=dist+1;
                    q.push({{newX,newY},dist+1});
                }
            }
        }
       return maxi; 
    }
};