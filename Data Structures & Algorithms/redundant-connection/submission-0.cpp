class Solution {
public:
    int find(int x, vector<int>& parents) {
        if (parents[x] < 0) 
            return x;
        return parents[x] = find(parents[x], parents);
    }

    bool unite(int a, int b, vector<int>& parents, vector<int>& size) {
        int rootA = find(a, parents),
            rootB = find(b, parents);
        
        if (rootA == rootB)
            return false;
        
        if (size[rootA] > size[rootB]) {
            swap(rootA, rootB);
        }

        parents[rootB] = rootA;
        size[rootA] += size[rootB];
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents(n + 1, -1), size(n + 1, 1);
        for (vector<int>& edge : edges) {
            if (!unite(edge[0], edge[1], parents, size)) {
                return edge;
            }
        }
        return {};
    }
};
