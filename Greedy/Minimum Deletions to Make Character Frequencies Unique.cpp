class Solution {
public:
    int minDeletions(string s) {
        set<int>  st;
        map<int, int> mp;
        int n = s.size();
        for(int i =0; i< n; i++){
            mp[s[i]]++;
        }
        vector<int> temp;
        for(auto p: mp){
            st.insert(p.second);
            temp.push_back(p.second);
        }
        sort(temp.begin(), temp.end());
        int ans = 0;
        for(int i = 1; i <temp.size(); i++){
            if(temp[i] == temp[i-1]){
                int ele = temp[i];
                while(st.find(ele) != st.end()){
                    ele--;
                    ans++;
                }
                if(ele != 0){
                    st.insert(ele);
                }
            }
        }
        return ans;
        
    }
};