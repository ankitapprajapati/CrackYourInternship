class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int i = 0, j = height.size()-1;
        int lmax = -1, rmax = -1;
        while(i<=j){
            if(lmax<rmax){
                if(min(lmax, rmax)>height[i]){
                    ans+=(min(lmax, rmax)-height[i]);
                }
                lmax = max(lmax, height[i]);
                i++;
            }else{
                if(min(lmax, rmax)>height[j]){
                    ans+=(min(lmax, rmax)-height[j]);
                }
                rmax = max(rmax, height[j]);
                j--;
            }
        }
        return ans;
    }
};