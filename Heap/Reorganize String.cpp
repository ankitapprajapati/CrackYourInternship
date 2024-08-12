class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(auto& ch: s){
            mp[ch]++;
        }

        priority_queue<pair<int,char>> pq;
        for ( auto& m: mp){
            pq.push(make_pair(m.second,m.first));
        }

        s="";
        pair<int,char> last={-1,'#'};

        while( !pq.empty() ){

            auto [count,ch]= pq.top();
            pq.pop();

            s+=ch;

            if(last.first > 0 ){
                pq.push(last);
            }

            last = {count-1,ch};

            if(pq.empty() && last.first>0){
                return "";
            }
        }
        return s;
    }
};