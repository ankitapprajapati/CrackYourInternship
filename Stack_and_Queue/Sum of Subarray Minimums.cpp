class Solution {
public:

    vector<int> findNSE(vector<int> &arr,int n){
        vector<int> nse(n,0);stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vector<int> &arr,int n){
        vector<int> psee(n,0);stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            psee[i]=st.empty() ? -1 :st.top();
            st.push(i);
        }
        return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nse=findNSE(arr,n);
        vector<int> psee=findPSEE(arr,n);
        int tot=0,mod=1e9+7;
        for(int i=0;i<n;i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            tot=(tot+(right*left*(long long)1*arr[i])%mod)%mod;
        }
        return tot;
    }
};