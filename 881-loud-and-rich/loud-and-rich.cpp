
class Solution {
private:
    void dfs(int u, vector<vector<int>>& adj, vector<int>& quiet, vector<int>& ans) {
        if (ans[u] != -1) return;

        ans[u] = u;

        for (auto v : adj[u]) {
            dfs(v, adj, quiet, ans);

            if (quiet[ans[v]] < quiet[ans[u]]) {
                ans[u] = ans[v];
            }
        }
    }

public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);

        for (auto it : richer) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            dfs(i, adj, quiet, ans);
        }

        return ans;
    }
};
