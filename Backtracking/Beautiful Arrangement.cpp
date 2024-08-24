class Solution {
public:
    int ans = 0;
    void backtrack(int level, int &number, int n){
        if(level == 0){
            ans++;
            return;
        }
        for(int i = n; i > 0; i--){
            if((number&(1<<i)) == 0){
                continue;
            }
            if((i%level)==0 || (level%i)==0){
                number ^= (1<<i);
                backtrack(level-1, number, n);
                number ^= (1<<i);
            }
        }
    }
    int countArrangement(int n) {
        ans = 0;
        int number = 0;
        for(int i = 1; i <= n; i++){
            number |= (1<<i);
        }
        backtrack(n, number, n);
        return ans;
    }
};