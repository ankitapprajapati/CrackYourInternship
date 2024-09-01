class Solution {
private:
    vector<int> dp;

    // Top-Down approach (Recursive with Memoization)
    int topDown(int n, vector<int> freq, int idx) {
        // Base case: If index exceeds the maximum value, return 0
        if (idx >= n) return dp[idx] = 0;

        // If already computed, return the stored value
        if (dp[idx] != -1) return dp[idx];

        // Option 1: Loot the current index and skip the next
        int loot = freq[idx] + topDown(n, freq, idx + 2);

        // Option 2: Skip the current index
        int skip = topDown(n, freq, idx + 1);

        // Store and return the maximum of the two choices
        return dp[idx] = max(loot, skip);
    }

    // Bottom-Up approach
    int bottomUp(int maxVal, vector<int> nums) {
        vector<int> arr(maxVal, 0);

        // Base cases
        arr[0] = 0;
        arr[1] = nums[1];

        // Fill the dp array with optimal subproblem solutions
        for (int i = 2; i < nums.size(); i++) {
            int loot = nums[i] + arr[i - 2]; // Loot the current and add to arr[i-2]
            int leave = arr[i - 1];          // Skip the current index

            arr[i] = max(loot, leave);       // Choose the maximum of loot and leave
        }

        return arr.back(); // The last element holds the result
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        // Find the maximum element in the input array
        auto it = max_element(nums.begin(), nums.end());
        vector<int> freq(*it + 1, 0);

        // Build the frequency array
        for (int i = 0; i < n; i++) {
            freq[nums[i]] += nums[i];
        }

        // Resize dp array for memoization in the top-down approach
        dp.resize(*it + 3, -1);

        // Solve using bottom-up dynamic programming
        int ans2 = bottomUp(*it + 1, freq);

        // Uncomment to use the top-down approach instead
        // return topDown(*it + 1, freq, 0);

        return ans2; // Return the result from the bottom-up approach
    }
};