class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // vector<int> ans;
        int l = 0, r = numbers.size() - 1;
        while(l < r) {
            int s = numbers[l] + numbers[r];
            cout << numbers[l] << " " << numbers[r] << " " << s << endl;
            if (s == target) 
                return {l + 1, r + 1};
            else if (s < target) 
                l++;
            else 
                r--;
        }
        return {};
    }
};
