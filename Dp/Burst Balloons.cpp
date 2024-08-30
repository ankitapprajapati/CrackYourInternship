class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int dp[n][n];

        // Gap strategy to fill the DP table
        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; i++, j++) {
                int maxVal = INT_MIN;

                // Try bursting each balloon in the range [i, j]
                for (int k = i; k <= j; k++) {
                    // Coins from left and right subarrays
                    int left = (k == i) ? 0 : dp[i][k - 1];
                    int right = (k == j) ? 0 : dp[k + 1][j];

                    // Coins from bursting balloon k
                    int val = (i == 0 ? 1 : nums[i - 1]) * nums[k] * (j == n - 1 ? 1 : nums[j + 1]);

                    // Total coins for this choice of k
                    int total = left + right + val;

                    // Keep track of the maximum coins obtainable
                    maxVal = max(maxVal, total);
                }
                dp[i][j] = maxVal;
            }
        }
        
        // The result is stored in dp[0][n-1], which covers the entire array
        return dp[0][n-1];
    }
};