class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;

        for(auto t:s)
        {
            if(!st.empty() && t==st.top().first)
            {
                st.top().second++;
            }
            else
            {
                st.push({t,1});
            }

            if(st.top().second==k)
            {
                st.pop();
            }
        }

        string result;

        while(!st.empty())
        {
            result.append(st.top().second,st.top().first);
            st.pop();
        }

        reverse(result.begin(),result.end());

        return result;


    }
};