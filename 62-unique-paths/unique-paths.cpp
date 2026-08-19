// class Solution {
// public:
// int unique(int i ,int j,int m ,int n,vector<vector<int>>&dp){
//     if(i==m-1&&j==n-1) return 1;
//     if(i>=m||j>=n) return 0;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int down = unique(i+1,j,m,n,dp);
//     int right = unique(i,j+1,m,n,dp);
//     return dp[i][j]=down+right;
// }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//        return unique(0,0,m,n,dp);
//     }
// };

class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,1));
        for(int i = m-2; i>=0;i--){
            for(int j = n-2; j>=0; j--){
                dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};