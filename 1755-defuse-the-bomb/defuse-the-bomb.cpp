class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>ans;
        for(int i = 0; i<n; i++){
            int sum = 0;
            if(k>0) {for(int j = i+1; j<=i+k; j++){
    
                sum+=code[j%n];
            }
            ans.push_back(sum);
            }
            else if(k<0) {for(int j = i-1; j>=i+k; j--){
                
                sum+=code[(j%n+n)%n];
            }
            ans.push_back(sum);
            }
            else {
                ans.push_back(0);
            }
            
        }
        return ans;
    }
};