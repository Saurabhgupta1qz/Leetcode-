class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
      sort(nums.begin(),nums.end());
      int n = nums.size();
      int temp = k;
      for(int i = 0; i<n; i++){
            if(nums[i]==temp){
                temp+=k;
            }
      }
      return temp;
    }
};