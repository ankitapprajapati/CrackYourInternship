
class Solution {
public:
    // Function to evaluate a postfix expression.
    int evaluatePostfix(string S) {
        stack<int> st1;

        for(int i = 0; i < S.length(); i++) {
            char c = S[i];

            // If the character is an operand, push it to the stack.
            if(isdigit(c)) {
                st1.push(c - '0'); // Convert character to integer
            }
            // If the character is an operator, pop two elements from the stack,
            // apply the operator, and push the result back to the stack.
            else {
                int val1 = st1.top();
                st1.pop();
                int val2 = st1.top();
                st1.pop();

                switch(c) {
                    case '+': st1.push(val2 + val1); break;
                    case '-': st1.push(val2 - val1); break;
                    case '*': st1.push(val2 * val1); break;
                    case '/': st1.push(val2 / val1); break;
                }
            }
        }
        // The final result is stored in the stack.
        return st1.top();
    }
};