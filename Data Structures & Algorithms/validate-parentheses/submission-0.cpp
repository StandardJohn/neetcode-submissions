class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (!stk.empty() && check(stk.top(), c)) {
                stk.pop();
                continue;
            }
            stk.push(c);
        }
        return stk.empty();
    }
    bool check(char c1, char c2) {
        return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');
    }
};
