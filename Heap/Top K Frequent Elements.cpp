class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (auto& num:nums){
            mp[num]++;
        }

        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
       
        for(auto it=mp.begin(); it!=mp.end(); it++){
            pq.push(make_pair(it->second,it->first));
            if( pq.size() >k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
        
    }
};