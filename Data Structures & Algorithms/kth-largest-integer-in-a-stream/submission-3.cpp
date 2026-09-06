class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int i : nums) {
            addHelper(i, k);
        }
    }

    void addHelper(int val, int k) {
        if (pq.size() < k) {
            pq.push(val);
        }
        else if (pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
    }

    int add(int val) {
        addHelper(val, k);
        return pq.top();
    }
};
