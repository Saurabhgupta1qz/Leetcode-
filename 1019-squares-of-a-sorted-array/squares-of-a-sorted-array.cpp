class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    //    int n = nums.size();
    //    for(int i = 0; i<n; i++){
    //     long long ans = nums[i]*nums[i];
    //     nums[i] = ans;
    //    }
    //    sort(nums.begin(),nums.end());
    //    return nums;
    int n = nums.size();
   vector<int>ans(n);
   int i = 0; 
   int j = n-1;
   int k = n-1;
   while(i<=j){
    if(abs(nums[i])>abs(nums[j])){
        ans[k] = nums[i]*nums[i];
        i++;
    }
    else{
        ans[k] = nums[j]*nums[j];
        j--;
    }
    k--;
   }
   return ans;
    }
};