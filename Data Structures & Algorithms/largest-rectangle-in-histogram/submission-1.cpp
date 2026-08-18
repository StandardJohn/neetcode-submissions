class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxArea = 0;
        vector<int> prefix(n, n - 1), suffix(n, 0);
        stack<int> s1, s2;
        for (int i = 0; i < n; i++) {
            while(!s1.empty() && heights[s1.top()] > heights[i]) {
                prefix[s1.top()] = i - 1;
                s1.pop();
            }
            s1.push(i);
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!s2.empty() && heights[s2.top()] > heights[i]) {
                suffix[s2.top()] = i + 1;
                s2.pop();
            }
            s2.push(i);
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
