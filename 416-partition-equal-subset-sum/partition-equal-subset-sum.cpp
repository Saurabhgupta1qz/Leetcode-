class Solution {
public:
bool check(int i ,vector<int>&nums,int target,vector<vector<int>>&dp){
    if(target==0) return true;
    if(i==0&&target!=0) return false;
    if(dp[i][target]!=-1) return dp[i][target];
    if(nums[i]<=target){
        int pick = check(i-1,nums,target-nums[i],dp);
        int notpick = check(i-1,nums,target,dp);
        return dp[i][target]=pick|notpick;
    }
    else {
        return dp[i][target] = check(i-1,nums,target,dp);
    }
    
}
  
    bool canPartition(vector<int>& nums) {
       int n = nums.size();
       int sum = 0;
       for(int i = 0; i<n; i++){
        sum+=nums[i];
       }
       int target = sum/2;
       vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
       if(sum%2==0){
        
        return check(n-1,nums,target,dp);
       }
       return false;
    }
};

// class Solution {
// public:
  
//     bool canPartition(vector<int>& nums) {
//        int n =  nums.size();
//        int sum = 0;
//      for(int i = 0; i<n; i++){
//         sum = sum+nums[i];
//        }
//        if(sum%2!=0) return false;
//        vector<vector<bool>>dp(n,vector<bool>((sum/2)+1,0));
//        for(int i = 0; i<n; i++) dp[i][0] = true;
//        if(nums[0]<=sum/2) dp[0][nums[0]] = true;
//        for(int i = 1; i<n; i++){
//         for(int target = 1; target<=sum/2;target++){
//             bool nottake = dp[i-1][target];
//             bool take = false;
//             if(nums[i]<=target){
//             take = dp[i-1][target-nums[i]];
//         }
//         dp[i][target] = take|nottake;
//         }
//        }
//        return dp[n-1][sum/2];
    
//     }
// };
// class Solution {
// public:
  
//     bool canPartition(vector<int>& nums) {
//        int n =  nums.size();
//        int sum = 0;
//      for(int i = 0; i<n; i++){
//         sum = sum+nums[i];
//        }
//        if(sum%2!=0) return false;
//        vector<bool>prev(sum/2+1,0),curr(sum/2+1,0);
//        prev[0] = curr[0] = true;
//        if(nums[0]<=sum/2) prev[nums[0]] = true;
//        for(int i = 1; i<n; i++){
//         for(int target = 1; target<=sum/2;target++){
//             bool nottake = prev[target];
//             bool take = false;
//             if(nums[i]<=target){
//             take = prev[target-nums[i]];
//         }
//         curr[target] = take|nottake;

//         }
//         prev = curr;
//        }
//        return prev[sum/2];
    
//     }
// };
