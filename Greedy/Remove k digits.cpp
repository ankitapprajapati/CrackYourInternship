class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char> st;
        int n = nums.length();

        // Edge case - 1 when k==n
        if (n == k)
            return "0";

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > nums[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }
        string ans;

        // edge case - 2
        //  when stack having increasing digits ie. 123456 and k=3
        //  need to remove top k digits
        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        // edge case - 3
        //  when string having leading zeros "0001012"
        /* long long num = stoi(ans);
        ans = to_string(num); */
        // Run time error

        // removing leading zeros
        int idx;
        for (int i = 0; i < ans.length(); i++) {
            if (ans[i] != '0') {
                idx = i;
                break;
            }
        }
        string new_ans = "";
        for (int i = idx; i < ans.length(); i++) {
            new_ans += ans[i];
        }
        return new_ans == "" ? "0" : new_ans;
    }
};