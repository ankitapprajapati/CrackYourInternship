class Solution {
private: 
    void findPairs(vector<int>& nums, vector<vector<int>>& ans){
        int n = nums.size();
        set<vector<int>> s;
        for( int i=0; i<n-1; i++ ){
            if( i>0 && nums[i]==nums[i-1] )continue;
            int j=i+1;
            int k=n-1;

            while(j<k){
                if(nums[i]+nums[j]+nums[k]>0) k--;
                else if(nums[i]+nums[j]+nums[k]<0) j++;
                else if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back( { nums[i],nums[j],nums[k] });
                    while( j<k && nums[j]==nums[j+1] ) j++;
                    while( j<k && nums[k]==nums[k-1] ) k--;
                    j++;
                    k--;
                }
            }
        } 
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        findPairs(nums,ans);
        return ans;                
    }
};