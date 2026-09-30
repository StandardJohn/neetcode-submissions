class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> umap;
        for (string& s : wordList) {
            string s1 = s;
            for (char& c : s1) {
                char t = c;
                c = '*';
                // cout << s1 << endl;
                umap[s1].push_back(s);
                c = t;
            }
        }

        // for (auto it = umap.begin(); it != umap.end(); ++it) {
        //     cout << it->first << ": ";
        //     for (string& s : it->second) {
        //         cout << s << " ";
        //     }
        //     cout << endl;
        // }

        queue<string> q;
        int minTrans = 1;
        unordered_set<string> uset;
        for (char& c : beginWord) {
            char t = c;
            c = '*';
            q.push(beginWord);
            // uset.insert(beginWord);
            c = t;
        }
        
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                string parent = q.front();
                // cout << parent << " " << minTrans << endl;
                q.pop();
                uset.insert(parent);
                auto it1 = umap.find(parent);
                if (it1 == umap.end()) {
                    // parnet not found
                    continue;
                }
                
                for (string& child : it1->second) {
                    // cout << "original: " << child << endl;
                    if (child == endWord) {
                        return minTrans + 1;
                    }
                    for (char& c : child) {
                        char t = c;
                        c = '*';
                        auto it2 = uset.find(child);
                        if (it2 != uset.end()) {
                            // visited
                            c = t;
                            continue;
                        }
                        // cout << child << endl;
                        q.push(child);
                        c = t;
                    }
                }
            }
            minTrans++;
        }

        return 0;
    }
};
