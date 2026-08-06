class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0, i = 0, j = heights.size() - 1;
        while (i < j) {
            area = max(area, (j - i) * min(heights[i], heights[j]));
            heights[i] <= heights[j] ? i++ : j--;
        }
        return area;
    }
};
