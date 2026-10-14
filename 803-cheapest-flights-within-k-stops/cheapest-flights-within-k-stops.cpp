class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<vector<pair<int,int>>>adjls(n);
      for(auto it : flights){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        adjls[u].push_back({v,wt});
      }
      vector<int>dist(n,1e9);
      dist[src] = 0;
      queue<pair<int,pair<int,int>>>q;
      q.push({0,{src,0}});//stops,node,dist;
      while(!q.empty()){
        int stops = q.front().first;
        int node = q.front().second.first;
        int dis = q.front().second.second;
        q.pop();
        if(stops>k) continue;
        for(auto it : adjls[node]){
            int edgeweight = it.second;
            int adjnode = it.first;
            if(dis+edgeweight<dist[adjnode]&&stops<=k){
                dist[adjnode] = dis+edgeweight;
                q.push({stops+1,{adjnode,dis+edgeweight}});
            }
        }
      }
      if(dist[dst]==1e9) return -1;
      return dist[dst];


    }
};