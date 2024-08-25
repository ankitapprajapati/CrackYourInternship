class Solution {
public:
void solve(vector<int>& arr, int n ,vector<vector<int>>& ans, vector<int>temp,int index){
        if(index == n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(arr[index]);
        solve(arr, n, ans,temp,index+1);
        temp.pop_back();
        while(index + 1 < n && arr[index] == arr[index+1]) index++;
        solve(arr,n,ans,temp,index+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> temp;
        int n = arr.size();
        vector<vector<int>> ans;
        solve(arr,n,ans,temp,0);
        
        return ans;
    }
};