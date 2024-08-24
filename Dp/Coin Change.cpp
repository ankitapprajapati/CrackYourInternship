class Solution {
public:
    int coinChange(vector<int>& a, int k) 
    {
        if(k==0)
            return 0;
        int n=a.size();
        sort(a.begin(),a.end());
        vector<long long int> dp(10005,INT_MAX);
        dp[0]=0;
        for(int i=0;i<10005;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i<a[j])
                    break;
                if(i==a[j])
                {
                    dp[i]=1;
                    break;
                }
                dp[i]=min(dp[i],(long long)1+dp[i-a[j]]);
            }
        } 
        if(dp[k]==INT_MAX)
            return -1; 
        return (int)dp[k];
    }
};