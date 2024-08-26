class Solution {
    int solve( int index, int transaction, vector<int>& prices,  vector<vector<int>> &dp ){

        if( index==prices.size() || transaction==0) return 0;
        
        if(dp[index][transaction]!=-1) return dp[index][transaction];

        int profit =0;
        if((transaction&1)==0){
            int take = -prices[index]+solve(index+1,transaction-1,prices,dp);
            int notTake = solve(index+1,transaction,prices,dp);
            profit = max(take,notTake);
        }else{
            int sell = prices[index]+solve(index+1,transaction-1,prices,dp);
            int notSell = solve(index+1,transaction,prices,dp);
            profit = max(sell,notSell);
        }
        return dp[index][transaction]=profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {

        int n=prices.size();

        vector<vector<int>> dp ( n,vector<int>(2*k+1,-1) );
        
        return solve( 0, 2*k, prices ,dp);
        
    }
};