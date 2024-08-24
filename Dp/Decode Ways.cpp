class Solution {
public:
    // int solve(int i, string s, vector<int>& dp){
    //     if(i >= s.size()) return 1;
    //     if(dp[i] != -1) return dp[i];
    //     int single = 0, doub = 0;

    //     if(s[i] != '0') single = solve(i+1, s, dp);
    //     else single = 0;
       
    //     if(i<s.size()-1 && ((s[i]- '0')*10 + (s[i+1] - '0')) >= 10 && ((s[i]- '0')*10 + (s[i+1] - '0')) <= 26) doub = solve(i+2, s, dp);
    //     else doub = 0;


    //     return dp[i] = single + doub;
    // }
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        //vector<int> dp(s.size()+1, 1);
        int one = 1, two = 1, curr = 0;
        for(int i = s.size()-1; i>=0; i--){
            int single = 0, doub = 0;

            if(s[i] != '0') single = one;
            else single = 0;

            if(i<s.size()-1 && ((s[i]- '0')*10 + (s[i+1] - '0')) >= 10 && ((s[i]- '0')*10 + (s[i+1] - '0')) <= 26) doub = two;
            else doub = 0;


            curr = single + doub;
            two = one;
            one = curr;
        }

        return one;
    }
};