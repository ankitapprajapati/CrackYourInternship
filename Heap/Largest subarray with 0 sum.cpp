
class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        // Your code here
        unordered_map<int,int> mp;
        int sum = 0 ; 
        int subArrSize=0;
        
        for( int i=0; i<n; i++ ){
            sum+=arr[i];
            if(sum==0){
                subArrSize = max( subArrSize,i+1 );
            }
            if (mp.find(sum)!=mp.end()  ){
                subArrSize = max( i-mp[sum],subArrSize);
            }else{
                mp[sum]=i;
            }
            
        }
        return subArrSize;
    }
};
