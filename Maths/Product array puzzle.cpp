
class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        long long int  product = 1;
        int countZero=0;
        
        for( auto num: nums){
            if( num == 0 ) {
                countZero++;
                continue;
            }
            product*=num;
        }
        
        vector<long long int> ans;
        for(auto num : nums ){
            if( countZero>1 || (countZero==1 && num !=0 ) ){
                ans.push_back(0);
            }else if( num==0 ){
                ans.push_back(product);
            }else{
                ans.push_back(product/num);
            }
        }
        return ans;
    }
};