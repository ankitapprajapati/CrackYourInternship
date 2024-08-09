class Solution {
public:
    bool backspaceCompare(string s, string t) 
    {
        string ss="",ts="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#')
            {
                if(ss.empty())
                {
                    continue;
                }
                ss.pop_back();
            }
            else
            {
               ss.push_back(s[i]); 
            }
        }
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='#')
            {
                if(ts.empty())
                {
                    continue;
                }
                ts.pop_back();
            }
            else
            {
               ts.push_back(t[i]); 
            }
        }
        return ss==ts;
    }
};