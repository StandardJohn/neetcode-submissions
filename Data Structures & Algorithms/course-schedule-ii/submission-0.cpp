class Solution {
public:
    bool dfs(vector<bool>& visiting, vector<bool>& visited, vector<int>& res, vector<vector<int>>& adj, int v) {
        if (visiting[v])
            return false;
        if (visited[v])
            return true;
        visiting[v] = true;
        for (int i = 0; i < adj[v].size(); i++) {
            if (!dfs(visiting, visited, res, adj, adj[v][i])) 
                return false;
        }
        visiting[v] = false;
        visited[v] = true;
        res.push_back(v);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<bool> visiting(n, 0), visited(n, 0);
        vector<vector<int>> adj(n);
        vector<int> res;
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < n; i++) {
            if (!dfs(visiting, visited, res, adj, i)) {
                return {};
            }
        }
        return res;
    }
};
