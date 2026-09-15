class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.empty() || (!left.empty() && num < left.top())) {
            left.push(num);
        }
        else {
            right.push(num);
        }
        size_t diff = left.size() > right.size() ? left.size() - right.size() : right.size() - left.size();
        if (!left.empty() && left.size() > right.size() && diff > 1) {
            right.push(left.top());
            left.pop();
        }
        else if (!right.empty() && right.size() - left.size() && diff > 1) {
            left.push(right.top());
            right.pop();
        }
        // cout << left.size() << " " << right.size() << endl;
    }
    
    double findMedian() {
        if (left.empty() && right.empty()) 
            return 0.0;
        if (left.empty())
            return (double) right.top();
        if (right.empty())
            return (double) left.top();
        if ((left.size() + right.size()) % 2 == 0)
            return (double) (left.top() + right.top()) / 2;
        else if (left.size() > right.size())
            return (double) left.top();
        else if (right.size() > left.size())
            return (double) right.top();
    }
};
