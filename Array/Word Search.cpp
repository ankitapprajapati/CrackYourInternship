class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(word[0]==board[i][j] && solve(board,word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool solve(vector<vector<char>>& board, string &word, int i, int j, int index){
        // base case
        if(index==word.length()){
            return true;
        }

        if (i<0 || i==board.size() || j<0 || j==board[0].size() || word[index] != board[i][j] ){
            return false;
        }

        char temp=board[i][j];
        board[i][j]='*';

        // found next char
        bool found =solve(board,word, i+1, j, index+1) ||
                    solve(board,word, i, j+1, index+1) ||
                    solve(board,word, i-1, j, index+1) ||
                    solve(board,word, i, j-1, index+1) ;
        board[i][j]=temp;

        return found;
    }    
};