class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        long long mod = 1e9 + 7;

        vector<vector<long long>> dp(n + 1, vector<long long>(26, 0));

        for(int i = 1; i <= n; i++) {
            int c = s[i - 1] - 'a';

            for(int j = 0; j < 26; j++) {
                dp[i][j] = dp[i - 1][j];
            }

            long long ways = 1;

            for(int j = 0; j < 26; j++) {
                ways = (ways + dp[i - 1][j]) % mod;
            }

            dp[i][c] = ways;
        }

        long long ans = 0;

        for(int j = 0; j < 26; j++) {
            ans = (ans + dp[n][j]) % mod;
        }

        return ans;
    }
};