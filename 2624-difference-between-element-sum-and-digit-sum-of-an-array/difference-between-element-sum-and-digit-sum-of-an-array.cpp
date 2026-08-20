class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elsum = 0;
        int digitsum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            elsum+=nums[i];
            int n = nums[i];
            while(n!=0){
                digitsum+=n%10;
                n = n/10;
            }
        }
        return abs(elsum-digitsum);
    }
};