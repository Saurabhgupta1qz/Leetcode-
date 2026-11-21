
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        vector<int> ans(n), last(26, -1);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';
            int prev = last[c];
            last[c] = u;

            for(int v : adj[u]) {
                dfs(v);
            }

            last[c] = prev;
        };

        vector<int> newParent(n, -1);
        fill(last.begin(), last.end(), -1);

        function<void(int)> build = [&](int u) {
            int c = s[u] - 'a';
            int prev = last[c];

            if(u != 0) {
                newParent[u] = (prev == -1 ? parent[u] : prev);
            }

            last[c] = u;

            for(int v : adj[u]) {
                build(v);
            }

            last[c] = prev;
        };

        build(0);

        vector<vector<int>> tree(n);
        for(int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        function<int(int)> calc = [&](int u) {
            int sz = 1;
            for(int v : tree[u]) {
                sz += calc(v);
            }
            return ans[u] = sz;
        };

        calc(0);
        return ans;
    }
};
