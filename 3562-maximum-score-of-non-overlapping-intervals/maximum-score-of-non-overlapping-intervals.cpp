class Solution {
public:
    using P = pair<long long, vector<int>>;

    vector<vector<int>> a;
    vector<vector<P>> dp;
    vector<vector<bool>> vis;

    P better(P x, P y) {
        if (x.first != y.first)
            return x.first > y.first ? x : y;

        return x.second < y.second ? x : y;
    }

    P solve(int i, int k) {
        if (i == a.size() || k == 0)
            return {0, {}};

        if (vis[i][k])
            return dp[i][k];

        vis[i][k] = true;

        P ans = solve(i + 1, k);

        int l = i + 1, r = a.size();

        while (l < r) {
            int m = l + (r - l) / 2;

            if (a[m][0] > a[i][1])
                r = m;
            else
                l = m + 1;
        }

        P take = solve(l, k - 1);
        take.first += a[i][2];
        take.second.push_back(a[i][3]);

        sort(take.second.begin(), take.second.end());

        return dp[i][k] = better(ans, take);
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        for (int i = 0; i < intervals.size(); i++)
            intervals[i].push_back(i);

        sort(intervals.begin(), intervals.end());

        a = intervals;

        int n = a.size();

        dp.assign(n, vector<P>(5));
        vis.assign(n, vector<bool>(5, false));

        return solve(0, 4).second;
    }
};