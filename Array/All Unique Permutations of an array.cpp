lass Solution {
private:
    void findPair(int j, vector<int> &arr ,int& n,vector<vector<int>>& ans, vector<int> temp,vector<int>& taken){
        if(temp.size()==n){
           ans.push_back(temp);
           return;
        }
        for( int i=0; i<n; i++){
            if(taken[i]==0){
                if (i > 0 && arr[i] == arr[i - 1] && taken[i - 1] == 0) continue;
                temp.push_back(arr[i]);
                taken[i]=1;
                findPair( i+1,arr,n,ans,temp,taken);
                taken[i]=0;
                temp.pop_back();
            }
        }
       
    }
public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> taken(n,0);
        findPair( 0,arr,n,ans,temp,taken);
        return ans;
    }
}