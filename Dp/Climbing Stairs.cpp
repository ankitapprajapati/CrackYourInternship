#include<unordered_map>

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int last = 1;
        int secLast =2;
        int curr = 0;
        for( int i=3 ; i<=n ; i++){
            curr= last + secLast;
            last = secLast;
            secLast = curr;
        }
        return secLast;
    }
};
