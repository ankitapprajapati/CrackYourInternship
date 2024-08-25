class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int n=s.length();
        int maxCnt=0;
        int maxLen=0;
        int l=0;
        vector<int>count(26,0);
        for(int r=0;r<n;r++)
        {   
            count[s[r]-'A']++;
            maxCnt=max(maxCnt,count[s[r]-'A']);
            while(r-l+1-maxCnt>k)
            {
                count[s[l]-'A']--;
                l++;
            }
            maxLen=max(maxLen,r-l+1);
        }
        return maxLen;
    }
};