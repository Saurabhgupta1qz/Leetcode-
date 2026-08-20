class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singlesum = 0;
        int doublesum = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]/10==0) singlesum+=nums[i];
            else doublesum+=nums[i];
        }
        return singlesum!=doublesum;
    }
};