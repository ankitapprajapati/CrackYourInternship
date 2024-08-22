#include<unordered_set>
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicate;
        for(int i=0; i<nums.size(); i++){
            // get index
            int getIndex=abs(nums[i])-1;

            // make -ve
            if(nums[getIndex]<0){
                duplicate.push_back(abs(nums[i]));
            }else{
                nums[getIndex]=-nums[getIndex];
            }
        }
        
        return duplicate;        
    }
};