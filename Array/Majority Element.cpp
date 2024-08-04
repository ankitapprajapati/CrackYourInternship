class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = nums.front();
        for (auto i: nums) {
            if (count == 0) {
                candidate = i;
                count++;
            } else if (count > 0) {
                if (i == candidate) {
                    count++;
                } else {
                    count--;
                }
            }
        }

        return candidate;
    }
};