class Solution {
public:
    int find(int x, vector<int>& parents) {
        if (parents[x] < 0) {
            return x;
        }
        return parents[x] = find(parents[x], parents);
    }
    bool unite(int& a, int& b, vector<int>& parents, vector<int>& size) {
        int rootA = find(a, parents),
            rootB = find(b, parents);
        if (rootA == rootB) 
            return false;

        if (size[a] > size[b]) {
            swap(a, b);
        }
        parents[rootA] = rootB;
        size[rootB] += size[rootA];
        return true;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n, -1), size(n, 1);
        int cnt = 0;
        for (vector<int>& e : edges) {
            unite(e[0], e[1], parents, size);
        }
        for (int& i : parents) {
            if (i < 0)
                cnt++;
        }
        return cnt;
    }
};
