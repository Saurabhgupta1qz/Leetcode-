class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int pairs = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i==j) continue;
                string s = "";
                s+=nums[i];
                s+=nums[j];
                if(s==target) pairs++;
            }
        }
        return pairs;
    }
};