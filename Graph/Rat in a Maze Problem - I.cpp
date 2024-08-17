class Solution {
    vector<pair<pair<int,int>,char>> directions= { {{0,1},'R'}, {{0,-1},'L'}, {{1,0},'D'}, {{-1,0},'U'}};
    
    void findPath( int x, int y, vector<vector<int>> &mat, vector<string>& ans, int n, string path ){
        // base case
        if( mat[x][y]==0 ) return ;
        if( x==n-1 && y==n-1) {
            ans.push_back(path);
            return ;
        }
        
        mat[x][y]=2;
        
        for( auto el:directions ){
            int newX = x+el.first.first;
            int newY = y+el.first.second;
            
            if(newX>=0 && newX<n && newY>=0 && newY<n && mat[newX][newY]==1){
                findPath(newX,newY,mat,ans,n,path+el.second);
            }
        }
        mat[x][y]=1;
        
    }
    
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n=mat.size();
        vector<string> ans;
        if( mat[0][0]==0) return ans;
        findPath(0,0,mat,ans,n,"");
        return ans;
    }
};