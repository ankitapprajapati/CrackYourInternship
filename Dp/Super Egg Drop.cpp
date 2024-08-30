class Solution {
public:
    int superEggDrop(int e, int f) 
    {
        /*recursion solution
        //base cases - if floor is one or zero return floor
        if(f==1 || f==0)
        {
            return f;
        }
        //worst case when number of eggs is one
        if(e==1)
        return f;

        int min = INT_MAX, x, res;
        //consider dropping from 1st floor 
        // we have two case either egg break or not
        // x is floor
        // break -> e-1, x-1
        // no break -> e, f-x
        for(x = 1; x<=f; x++)
        {
            res=max(superEggDrop(e-1,x-1), superEggDrop(e,f-x));
            if(res<min)
            min=res;
        }
        return min+1;
        */
        /* ------ DP SOLUTION ------
        int dp[f+1][e+1];
        for(int i=1; i<=f; i++)
        {
            dp[i][1]=i;
        }
        for(int i=1; i<=e; i++)
        {
            dp[1][i]=1;
            dp[0][i]=0;
        }
        for(int i=2; i<=f; i++)
        {
            for(int j=2; j<=e; j++)
            {
                dp[i][j]=INT_MAX;
                for(int x=1; x<=i; x++)
                {
                    dp[i][j] = min(dp[i][j], 1+ max(dp[x-1][j-1], dp[i-x][j]));
                }
            }
        }
        return dp[f][e];
        */
        //----- Futher optimised sol with BINARY SEARCH ------
         if (f == 0) return 0;
    if (e == 1) return f;

    std::vector<std::vector<int>> dp(f + 1, std::vector<int>(e + 1, 0));

    for (int i = 1; i <= f; ++i) {
        dp[i][1] = i; // Only one egg, we need to do linear search
    }

    for (int j = 1; j <= e; ++j) {
        dp[1][j] = 1; // Only one floor, only one attempt needed
    }

    for (int i = 2; i <= f; ++i) {
        for (int j = 2; j <= e; ++j) {
            dp[i][j] = INT_MAX;
            int low = 1, high = i;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int breakCase = dp[mid - 1][j - 1];
                int noBreakCase = dp[i - mid][j];
                if (breakCase > noBreakCase) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
                dp[i][j] = std::min(dp[i][j], 1 + std::max(breakCase, noBreakCase));
            }
        }
    }

    return dp[f][e];
    }
};