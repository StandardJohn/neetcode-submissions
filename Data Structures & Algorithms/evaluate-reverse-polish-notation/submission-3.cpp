class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans, t1 = 0, t2 = 0;
        char op;
        // bool flag = true;
        stack<int> nums;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].back() < '0' || tokens[i].back() > '9') {
                op = tokens[i][0];
                t1 = nums.top();
                nums.pop();
                t2 = nums.top();
                nums.pop();
                // cout << t1 << " " << t2 << " " << op << " ";
                t1 = operation(t2, t1, op);
                // cout << t1 << endl;
                nums.push(t1);
            }
            else {
                nums.push(stoi(tokens[i]));
                cout << i << ": " << nums.top() << endl;
                // if (flag) {
                //     ans = nums.top();
                //     flag = false;
                // }
            }
        }

        return nums.top();
    }
    int operation(int n1, int n2, char c) {
        if (c == '+')
            return n1 + n2;
        else if (c == '-')
            return n1 - n2;
        else if (c == '*')
            return n1 * n2;
        else
            return n1 / n2;
    }
};
