class Solution {
public:
    void solve(int i,vector<int>& candidates,vector<vector<int>>&ans,vector<int>&temp,int target){
        if(i==candidates.size()){
            if(target==0) ans.push_back(temp);
            return;
        }
        if(candidates[i]<=target){
            temp.push_back(candidates[i]);
            solve(i,candidates,ans,temp,target-candidates[i]);
            temp.pop_back();
        }
        solve(i+1,candidates,ans,temp,target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
     vector<vector<int>>ans;
     vector<int>temp;
     solve(0,candidates,ans,temp,target);
     return ans;
    }
};