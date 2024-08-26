class Solution {
private:


public:
    int maxArea(vector<int>& h) {
        int left = 0; 
        int right = h.size()-1; 
        int ans=0;
        while(left<right){
            ans= max( min(h[left],h[right])*(right-left) , ans );
            if(h[left]<=h[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};