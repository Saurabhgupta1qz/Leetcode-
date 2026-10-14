
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjls(n);
        int mod = 1e9 + 7;

        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adjls[u].push_back({v, wt});
            adjls[v].push_back({u, wt});
        }

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (cost > dist[node]) continue;

            for (auto it : adjls[node]) {
                int adjnode = it.first;
                int edgeweight = it.second;
                long long newDist = cost + edgeweight;

                if (newDist < dist[adjnode]) {
                    dist[adjnode] = newDist;
                    ways[adjnode] = ways[node];
                    pq.push({newDist, adjnode});
                }
                else if (newDist == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
