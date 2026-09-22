class Solution {
public:
    bool dfs(vector<bool>& visited, vector<bool>& visiting, vector<vector<int>>& adj, int v) {
        if (visiting[v])
            return false;
        if (visited[v])
            return true;
        for (int i = 0; i < adj[v].size(); i++) {
            // cout << v << " " << adj[v][i] << endl;
            visiting[v] = true;
            if (!dfs(visited, visiting, adj, adj[v][i]))
                return false;
            visiting[v] = false;
        }
        visited[v] = true;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, 0), visiting(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(visited, visiting, adj, i)) {
                return false;
            }
        }
        return true;
    }
};
