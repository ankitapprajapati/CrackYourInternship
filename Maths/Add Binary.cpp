class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int carry =0 ;

        int m = a.length()-1;
        int n = b.length()-1;

        while( m>=0 || n>=0 || carry) {

            if(m>=0 && a[m]=='1'){
                carry+=1;
            }
            if(n>=0 && b[n]=='1'){
                carry+=1;
            }

            s = char(carry%2+'0') + s;
            carry/=2;

            m--;
            n--;
        }
        return s;
        
    }
};