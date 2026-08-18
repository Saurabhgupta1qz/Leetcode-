// class Solution {
// public:
// bool check(int i ,vector<int>&nums,int target,vector<vector<int>>&dp){
//     if(target==0) return true;
//     if(i==0&&target!=0) return false;
//     if(dp[i][target]!=-1) return dp[i][target];
//     if(nums[i]<=target){
//         int pick = check(i-1,nums,target-nums[i],dp);
//         int notpick = check(i-1,nums,target,dp);
//         return dp[i][target]=pick|notpick;
//     }
//     else {
//         return dp[i][target] = check(i-1,nums,target,dp);
//     }
    
// }
  
//     bool canPartition(vector<int>& nums) {
//        int n = nums.size();
//        int sum = 0;
//        for(int i = 0; i<n; i++){
//         sum+=nums[i];
//        }
//        int target = sum/2;
//        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
//        if(sum%2==0){
        
//         return check(n-1,nums,target,dp);
//        }
//        return false;
//     }
// };

class Solution {
public:
  
    bool canPartition(vector<int>& nums) {
       int n =  nums.size();
       int sum = 0;
     for(int i = 0; i<n; i++){
        sum = sum+nums[i];
       }
       if(sum%2!=0) return false;
       int target = sum/2;
       vector<vector<bool>>dp(n+1,vector<bool>(target+1));
        for(int j = 0; j<=target; j++) dp[0][j] = false;
        for(int i = 0; i<=n;i++) dp[i][0] = true;
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=target;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]]|dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    
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
