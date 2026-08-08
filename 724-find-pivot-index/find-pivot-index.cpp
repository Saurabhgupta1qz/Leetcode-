class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int n = nums.size();
      int totalsum = 0;
      for(int i = 0; i<n; i++) totalsum+=nums[i];
    int leftsum = 0;
    for(int i = 0; i<n; i++){
        int rightsum = totalsum-leftsum-nums[i];
        if(rightsum==leftsum) return i;
        leftsum+=nums[i];
    }
    return -1;
    }
};