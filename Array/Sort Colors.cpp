class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countZero=0, countOne=0;
        for( auto& num: nums){
            if(num==0) countZero++;
            else if(num==1) countOne++;
        }

        for( int i=0; i<nums.size(); i++ ){
            if(countZero){
                nums[i]=0;
                countZero--;
            }else if(countOne){
                nums[i]=1;
                countOne--;
            }else{
                nums[i]=2;
            }
        }     
    }
};