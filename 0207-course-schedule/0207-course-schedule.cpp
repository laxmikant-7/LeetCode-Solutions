class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis)) return true;
            }
            else if (pathVis[it]) {
                return true; 
            }
        }

        pathVis[node] = 0; 
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> adj[n];

        for (int i = 0; i < p.size(); i++) {
            int u = p[i][1];
            int v = p[i][0];
            adj[u].push_back(v);
        }

        vector<int> vis(n, 0), pathVis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis)) return false;
            }
        }

        return true;
    }
};