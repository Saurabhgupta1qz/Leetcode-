class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      int maxprofit = 0;
      int miniprice = INT_MAX;
      for(int i = 0; i<n; i++){
        miniprice = min(miniprice,prices[i]);
        maxprofit = max(maxprofit,prices[i]-miniprice);
      }
      return maxprofit;
    }
};
