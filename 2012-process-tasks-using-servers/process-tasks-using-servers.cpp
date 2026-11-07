class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> av;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> bu;

        for (int i = 0; i < n; i++)
            av.push({servers[i], i});

        vector<int> ans(m);
        long long tm = 0;

        for (int i = 0; i < m; i++) {
            tm = max(tm, (long long)i);

            while (!bu.empty() && bu.top().first <= tm) {
                auto [f, id] = bu.top();
                bu.pop();
                av.push({servers[id], id});
            }

            if (av.empty()) {
                tm = bu.top().first;

                while (!bu.empty() && bu.top().first <= tm) {
                    auto [f, id] = bu.top();
                    bu.pop();
                    av.push({servers[id], id});
                }
            }

            auto [w, id] = av.top();
            av.pop();

            ans[i] = id;
            bu.push({tm + tasks[i], id});
        }

        return ans;
    }
};