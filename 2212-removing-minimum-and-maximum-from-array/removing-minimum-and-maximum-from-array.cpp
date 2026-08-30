class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        int k = 0, p = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == mini) k = i;
            if(nums[i] == maxi) p = i;
        }

        int l = min(k, p);
        int r = max(k, p);

        int left = r + 1;
        int right = n - l;
        int both = (l + 1) + (n - r);

        return min({left, right, both});
    }
};