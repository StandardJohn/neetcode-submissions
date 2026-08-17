class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // vector<int> cnt(100, 0);ß
        
        unordered_map<char, int> umap1, umap2;
        int cnt = 0, len = s1.size();
        for (char c : s1)
            umap1[c]++;
        for (int i = 0, j = 0; j < s2.size(); j++) {
            auto it1 = umap1.find(s2[j]);
            if (it1 != umap1.end()) {
                cnt++;
                umap2[s2[j]]++;
                while (umap2[s2[j]] > umap1[s2[j]]) {
                    umap2[s2[i]]--;
                    cnt--;
                    i++;
                }
            }
            else {
                umap2.clear();
                cnt = 0;
                i = j + 1;
            }
            if (cnt == len)
                return true;
            if (j - i + 1 > len) {
                umap2[s2[i]]--;
                cnt--;
                i++;
            }
            // cout << s2[j] << ", cnt = " << cnt << endl;
        }
        return false;
    }
};
