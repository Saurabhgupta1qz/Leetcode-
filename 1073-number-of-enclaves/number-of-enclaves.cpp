class Solution {
private: 
void dfs(int row , int col,vector<vector<int>>&vis,vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        int dr[] = {-1,0,+1,0};
        int dc[] = {0,+1,0,-1};
        for(int i = 0; i<4; i++){
            int nrow = row+dr[i];
            int ncol = col+dc[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0&&grid[nrow][ncol]==1){
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
       for(int i = 0; i<n ; i++){
        for(int j = 0; j<m; j++){
            if(i==0||i==n-1||j ==0||j==m-1){
                if(grid[i][j]==1){
                    dfs(i,j,vis,grid);
                }
            }
        }
       }
       int count = 0;
       for(int i = 0; i<n; i++){
        for(int j = 0; j<m ; j++){
            if(grid[i][j]==1&&vis[i][j]==0) count++;
        }
       }
       return count;
    }
};