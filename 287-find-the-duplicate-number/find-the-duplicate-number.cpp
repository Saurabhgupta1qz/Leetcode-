class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // for(int i = 0; i<n-1; i++){
        //     if(nums[i]==nums[i+1]){
        //         return nums[i];
        //     }
        // }
        // return -1;
        // int n = nums.size();
        // unordered_map<int,int>mp;
        // for(int i = 0; i<n; i++){
        //     mp[nums[i]]++;
        // if(mp[nums[i]]>=2) return nums[i];
        // }
        
        // return -1;
        int slow = nums[0];
        int fast = nums[0];
        while(true){
            slow= nums[slow];

            fast = nums[nums[fast]];
            if(slow==fast) break;
        }
        slow =nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};