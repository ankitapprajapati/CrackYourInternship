class Solution {
private:
    vector<pair<int, int>> path;
    vector<vector<string>> res;

    // pass -> true
    bool check(vector<pair<int, int>>& a, pair<int, int>& b) {
        bool pass = true; 
        for (int i = 0; i < a.size(); i ++) {
            if (a[i].second == b.second || abs(a[i].first - b.first) == abs(a[i].second - b.second))
                pass = false;
        }
        return pass;
    }

    void backtracking(int n, int t, int prev, vector<string>& chess) {
        if (n + 1 == t) {
            res.push_back(chess);
            return;
        }

        for (int i = 1; i <= n; i ++) {
            if (t != 1 && (i == prev || i == prev - 1 || i == prev + 1))
                continue;
            pair<int, int> tmp = {t, i};
            if (check(path, tmp)) {
                path.push_back(tmp);
                chess[t-1][i-1] = 'Q';
                backtracking(n, t + 1, i, chess);
                path.pop_back();
                chess[t-1][i-1] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chess(n, string(n, '.'));
        backtracking(n, 1, 0, chess);
        return res;
    }
};