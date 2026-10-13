class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        //{diff,{row,col}};
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int dr[] = {-1,0,+1,0};
        int dc[] = {0,+1,0,-1};
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int diff = pq.top().first;
            pq.pop();
            if(row == n-1&&col == m-1) return diff;
            for(int i =0; i<4; i++){
                int nrow= row+dr[i];
                int ncol = col+dc[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m){
                    int neweffort = max(abs(heights[nrow][ncol]-heights[row][col]),diff);
                    if(neweffort<dist[nrow][ncol]){
                        pq.push({neweffort,{nrow,ncol}});
                        dist[nrow][ncol] = neweffort;
                    }
                }
            }
        }
        return -1;

    }
};