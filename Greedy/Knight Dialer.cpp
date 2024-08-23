class Solution {
    int mod = 1000000007;

    int solve(int n, int cell , vector<vector<int>>& directions ,vector<vector<int>>& dp ){
        if(n==1) {
            return 1;
        }

        if( dp[n][cell]!=-1) return dp[n][cell] ;

        int ans =0;
        for( auto newCell : directions[cell] ){
            ans = (ans+solve(n-1,newCell,directions,dp))%mod ;            
        }
        return dp[n][cell] = ans;
    } 
public:
    int knightDialer(int n) {
        vector<vector<int>> directions = { {4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
        vector<vector<int>> dp (n+1,vector<int>(10,-1));
        int count =0;
        for( int i=0; i<=9; i++){
            if( dp[n][i]!=-1){
                count = (count + dp[n][i]) %mod;
            }else{
                count = (count+solve(n,i,directions,dp)) %mod;
            }
        }
        return count;                
    }
};