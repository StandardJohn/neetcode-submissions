class PrefixTree {
public:
    class TrieNode {
    public:
        vector<TrieNode*> children;
        bool end;
        TrieNode() : children(26, nullptr) , end(false) {};
    };

    TrieNode* root;

    PrefixTree() : root(new TrieNode) {
    }
    
    void insert(string word) {
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
        TrieNode* node = root;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i])
                return false;
            node = node->children[i];
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (!node->children[i])
                return false;
            node = node->children[i];
        }
        return true;
    }
};
