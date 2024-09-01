class Solution {
    void generate(int n, int countOp, int countCl, string s, vector<string>& ans ){
        if ( countOp>n || countCl>n || countOp<countCl) return ;

        if(s.length() == 2*n){
            ans.push_back(s);
            return ;
        }

        generate(n , countOp+1, countCl, s+'(', ans) ;
        generate(n , countOp, countCl+1 , s+')', ans)  ;
        
        
    }
public:
    vector<string> generateParenthesis(int n) {
        int countOp = 0;
        int countCl = 0;
        vector<string> ans;
        string s = "" ;
        generate(n , countOp, countCl,s, ans)  ;
        return ans;      
    }
};