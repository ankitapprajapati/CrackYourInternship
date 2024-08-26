class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans =0;
        unordered_map<int,int> mp;
        mp[0]++;

        int sum =0;

        for( int i=0; i<nums.size(); i++ ){
            sum += nums[i] ;
            // while(sum<0)  sum+=k;
            sum = ((sum%k)+k)%k;
            ans+=mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};