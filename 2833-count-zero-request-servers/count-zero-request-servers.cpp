class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& q) {
        sort(logs.begin(), logs.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        vector<int> ans(q.size());
        vector<pair<int,int>> v;

        for (int i = 0; i < q.size(); i++)
            v.push_back({q[i], i});

        sort(v.begin(), v.end());

        unordered_map<int,int> mp;
        int l = 0, r = 0;

        for (auto [t, idx] : v) {
            while (r < logs.size() && logs[r][1] <= t)
                mp[logs[r++][0]]++;

            while (l < r && logs[l][1] < t - x)
                if (--mp[logs[l++][0]] == 0)
                    mp.erase(logs[l-1][0]);

            ans[idx] = n - mp.size();
        }

        return ans;
    }
};