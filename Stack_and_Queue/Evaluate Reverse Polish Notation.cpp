class Solution {
public:
        
    bool isSign(string s)
    {
        return s=="+" || s=="-" || s=="*" || s=="/" ;
    }
    int calculate(int a, int b, string s)
    {
        if(s=="+")
            return a+b;
        else if(s=="-")
            return a-b;
        else if(s=="*")
            return a*b;
        else if(s=="/")
            return a/b;
        else 
            return 0;
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size(), ans=0;
        stack<int> st;
        for(int i=0;i<n;i++)
        {  
            if(tokens[i].size()==1 && isSign(tokens[i]))
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(calculate(b, a, tokens[i]));
            }
            else
                st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};