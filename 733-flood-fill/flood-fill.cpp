class Solution {
public:
void dfs(int row,int col,vector<vector<int>>&image,int color,vector<vector<int>>&ans,int inicolor){
    ans[row][col] = color;
    int n = image.size();
    int m = image[0].size();
    int dr[] = {-1,0,+1,0};
    int dc[] = {0,+1,0,-1};
    for(int i = 0; i<4; i++){
        int nrow = row+dr[i];
        int ncol = col+dc[i];
        if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&image[nrow][ncol]==inicolor&&ans[nrow][ncol]!=color){
            dfs(nrow,ncol,image,color,ans,inicolor);
        }
    }

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      vector<vector<int>>ans = image;
      int inicolor = image[sr][sc];
      dfs(sr,sc,image,color,ans,inicolor);
      return ans;
    }
};