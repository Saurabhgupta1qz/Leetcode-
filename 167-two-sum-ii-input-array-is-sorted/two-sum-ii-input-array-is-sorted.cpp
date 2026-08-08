// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         unordered_map<int,int>nump;
//         int n = numbers.size();
//         for(int i = 0; i<n;i++){
//            int complement = target - numbers[i];
//            if(nump.count(complement)){
//             return{nump[complement]+1,i+1};//index in mpp at complement value
//            }
//            nump[numbers[i]]= i;
//         }
//         return{};
//     }
// };


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
   int left = 0;
   int right = numbers.size()-1;
   while(left<right){
    int sum = numbers[left]+numbers[right];
    if(sum==target) return {left+1,right+1};
    else if(sum<target) left++;
    else right--;
   }
   return {};
    }
};


