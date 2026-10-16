
class Solution {
public:
    static const int mod = 1e9 + 7;

    vector<long long> sum, sq, lazy;

    void push(int node, int l, int r) {
        if(lazy[node] == 0) return;

        long long v = lazy[node];
        long long len = r - l + 1;

        sq[node] = (sq[node] + 2 * v % mod * sum[node] % mod
                    + v * v % mod * len % mod) % mod;

        sum[node] = (sum[node] + v * len) % mod;

        if(l != r) {
            lazy[node * 2] = (lazy[node * 2] + v) % mod;
            lazy[node * 2 + 1] = (lazy[node * 2 + 1] + v) % mod;
        }

        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        push(node, l, r);

        if(r < ql || l > qr) return;

        if(ql <= l && r <= qr) {
            lazy[node] = (lazy[node] + 1) % mod;
            push(node, l, r);
            return;
        }

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % mod;
        sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % mod;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last;
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            int p = -1;

            if(last.count(nums[i])) {
                p = last[nums[i]];
            }

            update(1, 0, n - 1, p + 1, i);

            last[nums[i]] = i;

            ans = (ans + sq[1]) % mod;
        }

        return ans;
    }
};
