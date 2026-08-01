class MinStack {
public:
    struct Node {
        int val;
        Node* next;
        // Node () : val(0), next(nullptr) {} 
        Node(int val) : val(val), next(nullptr) {}
    };
    Node* head;
    stack<int> minimum;

    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        if (!head) {
            head = new Node(val);
            minimum.push(val);
        }
        else {
            Node* temp = head;
            head = new Node(val);
            head->next = temp;
            int n = min(minimum.top(), val);
            minimum.push(n);
        }
        return;
    }
    void pop() {
        Node *temp = head;
        head = head->next;
        delete temp;
        minimum.pop();
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return minimum.top();
    }
};
