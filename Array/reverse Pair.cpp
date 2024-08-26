class Solution {
    void merge(vector<int>& nums, int start, int mid, int end, int& ans) {
        int j = mid + 1;
        
        // Count reverse pairs
        for (int i = start; i <= mid; i++) {
            while (j <= end && nums[i] > 2LL * nums[j]) {
                j++;
            }
            ans += (j - (mid + 1));
        }

        // Merge step
        vector<int> temp(end - start + 1);
        int i = start, k = 0;
        j = mid + 1;
        
        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        
        while (i <= mid) temp[k++] = nums[i++];
        while (j <= end) temp[k++] = nums[j++];
        
        for (int i = start; i <= end; i++) {
            nums[i] = temp[i - start];
        }
    }

    void mergeSort(vector<int>& nums, int start, int end, int& ans) {
        if (start >= end) return;
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid, ans);
        mergeSort(nums, mid + 1, end, ans);
        merge(nums, start, mid, end, ans);
    }

public:
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        mergeSort(nums, 0, nums.size() - 1, ans);
        return ans;
    }
};
