class Solution {
public:
bool check(string s){
    int i =0;
    int j = s.length()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;

}
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for(int i = 0; i<n; i++){
            string s = words[i];
            if(check(s)) return s;
        }
        return "";
    }
};