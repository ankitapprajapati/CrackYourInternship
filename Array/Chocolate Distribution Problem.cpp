class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        long long mini = 10e9;
        for( int i=0; i<(n-m+1); i++){
            mini = min( mini, abs(a[i]-a[i+m-1]));
        }
        return mini;
    }   
}