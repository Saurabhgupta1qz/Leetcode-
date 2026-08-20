class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // for(int i = 0; i<nums.size()-1;i++){
        //         swap(nums[i],nums[i+1]);
        // }
        int i = 0;
        int j = 1;
        int n =  nums.size();
        while(i<n-1){
            swap(nums[i],nums[j]);
            i+=2;
            j+=2;
        }
        return nums;
    }
};