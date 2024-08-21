class Solution {
public:
    int maxProfit(vector<int>& arr) {
        // traverse from 0 -----> n-1 and maintain the min
        int min =arr[0];
        int ans= 0;
        for(int i=1; i<arr.size(); i++){
            if(arr[i]<min){
                min=arr[i];
            }
            else{
                if(arr[i]-min>ans){
                ans= arr[i]-min;}
            }
        }
        return ans;
        
    }
};