class Solution {
    int solve(int m, int n , vector<vector<int>>& dp){
        
        if(m<0 || n<0 )  return 0;
        if( dp[m][n]!=-1 ) return dp[m][n];
        int right = solve(m,n-1,dp);
        int down = solve(m-1,n,dp);
        return dp[m][n]=right+down;
    }
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        int path = solve(m-1,n-1,dp);
        return path;        
    }
};