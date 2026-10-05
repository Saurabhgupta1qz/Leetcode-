class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vis[row][col] = 1;
        q.push({row, col});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   !vis[nrow][ncol] &&
                   grid[nrow][ncol] == '1') {

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {

                if(!vis[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, grid, vis);
                }
            }
        }

        return count;
    }
};