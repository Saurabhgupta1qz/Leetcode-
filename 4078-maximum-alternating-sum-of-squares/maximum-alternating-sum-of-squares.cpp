class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
      int n = nums.size();
      long long ans = 0;
      for(int i = 0; i<n; i++){
        nums[i] = 1LL*nums[i]*nums[i];
      }
      sort(nums.begin(),nums.end());
      for(int i = 0; i<n; i++){
        long long x = nums[i];
        if(i<n/2){
            ans-=x;
        }
        else{
            ans+=x;
        }
      }
      return ans;
    }
};