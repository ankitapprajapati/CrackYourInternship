class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n = c.size();
        int maxi = 0;
        int sum =0;
        for ( int i=0; i<k; i++ ){
            sum+=c[i];
        }
        maxi = sum;

        for(int i=0; i<k; i++ ){
            sum = sum-c[k-i-1]+c[n-i-1];
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};