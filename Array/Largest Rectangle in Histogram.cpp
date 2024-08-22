class Solution {
private: 
    vector<int> getPrevIndex(vector<int>&arr,int &n, vector<int> &prev){
        stack<int> st;
        st.push(-1);
        for(int i=0; i<n; i++){
            while( st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.top()==-1){
                prev[i]=-1;
            }else{
                prev[i]=st.top();
            }
            st.push(i);
        }
        return prev;
    } 

    vector<int> getNextIndex(vector<int>&arr,int &n, vector<int> &next){
        stack<int> st;
        st.push(n);
        for(int i=n-1; i>=0; i--){
            while( st.top()!=n && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.top()==n){
                next[i]=n;
            }else{
                next[i]=st.top();
            }
            st.push(i);
        } 
        return next;
    }

public:
    int largestRectangleArea(vector<int>& arr) {

        int n= arr.size();

        vector<int> prev(n);
        prev=getPrevIndex(arr,n,prev);

        vector<int> next(n);
        next=getNextIndex(arr,n,next);

        int maxArea=0;
        for (int i=0; i<n; i++ ){
            if((next[i]-prev[i]-1)*arr[i]>maxArea){
                maxArea=(next[i]-prev[i]-1)*arr[i];
            }
        }
        return maxArea;
    }
};