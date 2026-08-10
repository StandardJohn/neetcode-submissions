class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n = temperatures.size(), t = s.top();
        vector<int> res(n, 0);
        s.push(0);
        for (int i, j = 1; j < n; j++) {
            // i = s.top();
            while(!s.empty() && temperatures[j] > temperatures[s.top()]) {
                i = s.top();
                // cout << i << " " << j << " " << temperatures[j] << endl;
                res[i] = j - i;
                s.pop();
            }
            s.push(j);
        }
        return res;
    }
};
