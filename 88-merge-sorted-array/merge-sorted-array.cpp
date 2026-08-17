class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0&&j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k] = nums1[i];
                i--;

            }
            else{
                nums1[k]= nums2[j];
                j--;
            }
            k--;
        }
        while(j>=0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
//    vector<int>merge(m+n);
//    int i = 0;
//    int j = 0;
//    int k = 0;
//    while(i<m&&j<n){
//     if(nums1[i]>nums2[j]){
//         merge[k] = nums2[j];
//         j++;
//     }
//     else{
//         merge[k] = nums1[i];
//         i++;
//     }
//     k++;
//    }
//    while(i<m){
//     merge[k] = nums1[i];
//     k++;
//     i++;
//    }
//    while(j<n){
//     merge[k] = nums2[j];
//     k++;
//     j++;
//    }
//    for(int p = 0; p<(m+n);p++){
//     nums1[p] = merge[p];
//    }
    }
};