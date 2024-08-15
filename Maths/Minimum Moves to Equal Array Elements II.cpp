class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int m=n/2;
        int a=0;
        int b=0;
        for(int i=0;i<m;i++){
            a+=nums[m]-nums[i];
        }
        for(int j=n-1;j>m;j--){
            b+=nums[j]-nums[m];
        }
        return a+b;
        
    }
};