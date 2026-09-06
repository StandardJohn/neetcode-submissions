class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int i : nums) {
            add(i);
        }
    }

    int add(int val) {
        if (pq.size() < k) {
            pq.push(val);
        }
        else if (pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};
