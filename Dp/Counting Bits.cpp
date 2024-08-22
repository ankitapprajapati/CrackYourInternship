class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans (n+1,-1);
        ans[0]=0;

        for( int i=1; i<=n; i++){
            int count =0;
            int temp = i; 

            while( temp!=0 ){
                if( ans[temp]!=-1 ){
                    count=ans[temp]+count;
                    break;
                }
                if( temp&1 ){
                    count++;
                }   
                temp = temp >> 1;           
            }
            ans[i]=count;
        }
        return ans;   
    }
};