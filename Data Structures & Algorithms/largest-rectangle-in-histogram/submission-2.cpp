class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxArea = 0;
        vector<int> prefix(n, n - 1), suffix(n, 0);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while(!s.empty() && heights[s.top()] > heights[i]) {
                prefix[s.top()] = i - 1;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                suffix[s.top()] = i + 1;
                s.pop();
            }
            s.push(i);
        }
        // for (int i = 0; i < n; i++) {
        //     cout << prefix[i] << " " << suffix[i] << endl;
        // }
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, (prefix[i] - suffix[i] + 1) * heights[i]);
        }
        return maxArea;
    }
};
