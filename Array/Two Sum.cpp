class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(make_pair(nums[i],i));
        }
        sort(ans.begin(),ans.end());
        int i=0,j=ans.size()-1;
        while(i<j){
            int sum=ans[i].first+ans[j].first;
            if(sum==target){
                return {ans[i].second,ans[j].second};
                i++;
                j--;
            }
            else if(sum>target){
                j--;
            }
            else{
                i++;
            }
        }
        
        return {};
        
    }
};