class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long xSum = 0;
        int xMax = 0, ans;
        for (int i = 0; i < piles.size(); i++) {
            xMax = max(xMax, piles[i]);
            xSum += i;
        }
        if (h == piles.size())
            return xMax;

        int l = 1, r = xMax, m;
        while (l <= r) {
            m = l + (r - l) / 2;
            int h_used = 0;
            for (int i = 0; i < piles.size() && h_used <= h; i++) {
                h_used += (piles[i] + m - 1) / m;
            }
            // cout << m << " " << h_used << endl;
            // if (h_used == h) {
            //     ans = m;
            //     break; 
            // }
            if (h_used <= h) {
                r = m - 1;
                ans = m;
            }
            else 
                l = m + 1;
        }
        return ans;
    }
};
