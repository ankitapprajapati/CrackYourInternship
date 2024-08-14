class Solution {
private:

    void solve(int start, int target, vector<int> arr ,vector<vector<int>>& result , vector<int>& candidates){
        if ( target<0) return ;
        if( target==0 ){
            result.push_back(arr);
            return;
        }

        for(int i=start; i<candidates.size(); i++){

            if (i > start && candidates[i] == candidates[i - 1]) continue;

            if( candidates[i] > target ) break;
            arr.push_back(candidates[i]);
            solve( i+1, target-candidates[i],arr,result,candidates);
            arr.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result; 
        sort(candidates.begin(),candidates.end());
        vector<int> arr;
        solve(0,target,arr,result,candidates);
        return result;
    }
};