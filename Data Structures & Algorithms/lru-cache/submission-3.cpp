class LRUCache {
public:
    struct Node {  
        int key = -1;
        int val;
        Node *prev;
        Node *next;
        Node (int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    unordered_map<int, Node*> umap;
    int n;
    
    LRUCache(int capacity) : n(capacity), head(nullptr), tail(nullptr) {
        
    }
    
    void update(Node* node) {
        if (head == tail || node == tail) {
            return;
        }
        if (node == head) {
            head = head->next;
            head->prev = nullptr;

            node->prev = tail;
            node->next = nullptr;

            tail->next = node;
            tail = node;
        }
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->prev = tail;
            node->next = nullptr;
            tail->next = node;
            tail = node;
        }
    }

    int get(int key) {
        auto it = umap.find(key);
        if (it == umap.end()) 
            return -1;
        
        Node* node = it->second;
        update(node);

        return node->val;
    }
    
    void put(int key, int value) {
        auto it = umap.find(key);
        if (it != umap.end()) {
            it->second->val = value;
            update(it->second);
            return;
        }
        
        Node* node = new Node(key, value);
        if (!head) {
            head = node;
            tail = node;
        }
        else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        umap.insert({key, node});
        if (umap.size() > n) {
            Node* t = head;
            head = head->next;
            umap.erase(t->key);
            cout << t->key << " " << t->val << endl;
            // delete t;
        }
    }

};