class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> mat(m, vector<int> (n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int noOfOnes = 0;
                if(i >= 1){
                    if(board[i - 1][j] == 1){
                        noOfOnes++;
                    }
                }
                if(i <= m - 2){
                    if(board[i + 1][j] == 1){
                        noOfOnes++;
                    }
                }
                if(j >= 1){
                    if(board[i][j - 1] == 1){
                        noOfOnes++;
                    }
                }
                if(j <= n - 2){
                    if(board[i][j + 1] == 1){
                        noOfOnes++;
                    }
                }
                if(i >= 1 && j >= 1){
                    if(board[i - 1][j - 1] == 1){
                        noOfOnes++;
                    }
                }
                if(i <= m - 2 && j <= n - 2){
                    if(board[i + 1][j + 1] == 1){
                        noOfOnes++;
                    }
                }
                if(i >= 1 && j <= n - 2){
                    if(board[i - 1][j + 1] == 1){
                        noOfOnes++;
                    }
                }
                if(i <= m - 2 && j >= 1){
                    if(board[i + 1][j - 1] == 1){
                        noOfOnes++;
                    }
                }
                mat[i][j] = board[i][j];
                if(noOfOnes < 2){
                    mat[i][j] = 0;
                }
                if(noOfOnes == 3){
                    mat[i][j] = 1;
                }
                if(noOfOnes > 3){
                    mat[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = mat[i][j];
            }
        }
    }
};