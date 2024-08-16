class Solution {
    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(vector<vector<char>>& grid,int curR, int curC, int rows, int cols){
        if (curR>=0 && curR<rows && curC>=0 && curC<cols && grid[curR][curC]=='1'){
            grid[curR][curC]='2';
            for (const auto& d: dirs){
                dfs(grid,curR+d[0],curC+d[1],rows,cols);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size(),c = grid[0].size();
        int ans=0;
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                if (grid[i][j]=='1') ans++,dfs(grid,i,j,r,c);
            }
        }
        return ans;
    }
};