class Solution {
private:
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCount=0;
        int i=0;
        int j=0;
        while( j<nums.size() ){
            if(nums[j]==0){
                j++;
            }else{
                nums[i++]=nums[j++];
            }
        } 
        for(int k=i; k<nums.size(); k++){
            nums[k]=0;
        }
    }
};