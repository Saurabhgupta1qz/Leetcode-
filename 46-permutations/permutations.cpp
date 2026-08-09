class Solution {
public:
vector<vector<int>>ans;
void solve(int mask,vector<int>&v,vector<int>&nums){
    int n = nums.size();
    if(mask==(1<<n)-1){
        ans.push_back(v);
        return;
    }
    for(int i = 0; i<n; i++){
        if(mask&(1<<i)) continue;
        v.push_back(nums[i]);
        solve (mask|1<<i,v,nums);
        v.pop_back();
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>v;
        solve(0,v,nums);
        return ans;
    }
};