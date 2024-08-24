class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size()-1;
        int prefix = 1;
        int suffix = 1;
        int product=INT_MIN;

        for( int i=0; i<=n ; i++ ){
            if(!suffix) suffix = 1;
            if(!prefix) prefix = 1;
            suffix*=nums[i];
            prefix*=nums[n-i];
            product = max(product,max(suffix,prefix));
        }
        return product;
        
    }
};