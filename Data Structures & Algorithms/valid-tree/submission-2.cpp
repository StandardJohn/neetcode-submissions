class Solution {
public:
    bool dfs(vector<bool>& visited, vector<vector<int>>& adj, int u, int v) {
        if (visited[v]) 
            return true;
        visited[v] = true;
        for (int i = 0; i < adj[v].size(); i++) {
            // cout << v << " " << adj[v][i] << endl;
            if (visited[adj[v][i]] && adj[v][i] != u || !dfs(visited, adj, v, adj[v][i]))
                return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if (!dfs(visited, adj, -1, 0))
            return false;
        for (bool f : visited) {
            if (!f) {
                return false;
            }
        }
        return true;
    }
};