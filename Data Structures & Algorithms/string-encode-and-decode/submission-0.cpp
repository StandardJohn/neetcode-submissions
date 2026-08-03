class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for (int i = 0; i < strs.size(); i++) {
            s += to_string(strs[i].size()) + "#" + strs[i];
        }
        cout << s << endl;
        return s;
    }

    vector<string> decode(string s) {
        if (s == "")
            return {};
        vector<string> strs;
        int size = 0;
        // size_t pos = s.find("#"), oldPos = 0;
        // while (pos != string::npos) {
        //     string sizeStr = s.substr(oldPos, pos);
        //     oldPos = pos + 1;
        //     size = stoi(sizeStr);
        //     string contentStr = s.substr(oldPos, size);
        //     pos = s.find("#", oldPos);
        //     cout << size << " " << contentStr << endl;
        // }
        for (int i = 0, j = 0; i < s.size() && j < s.size();) {
            if (s[j] == '#') {
                string sizeStr = s.substr(i, j - i);
                int size = stoi(sizeStr);
                strs.push_back(s.substr(j + 1, size));
                // string contentStr = s.substr(j + 1, size);
                // cout << sizeStr << " " << contentStr << endl;
                i = j + 1 + size;
                j = j + 2 + size;
            }
            else
                j++;
        }
        return strs;
    }
};
