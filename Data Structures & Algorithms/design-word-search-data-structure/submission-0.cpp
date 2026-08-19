class WordDictionary {
public:
    struct TrieNode {
        vector<TrieNode*> children;
        bool end;
        TrieNode() : children(26, nullptr), end(false) {};
    };

    TrieNode *root;

    WordDictionary() : root(new TrieNode()) {

    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i]) {
                node->children[i] = new TrieNode();
            }
            node = node->children[i];
        }
        node->end = true;
    }
    
    bool search(string word) {
          return searchHelper(word, 0, root);
    }

    bool searchHelper(string& word, int i, TrieNode* node) {
        // cout << i << " " << word.size() - 1 << " " << word[i] << " " << node->end << endl;
        if (i == word.size()) {
            return node->end;
        }
        int idx = word[i] - 'a';
        if (idx < 0) {
            for (int j = 0; j < 26; j++) {
                if (node->children[j] && searchHelper(word, i + 1, node->children[j])) {
                    return true;
                }
            }
            return false;
        }
        else {
            return node->children[idx] && searchHelper(word, i + 1, node->children[idx]);
        }
    }
};
