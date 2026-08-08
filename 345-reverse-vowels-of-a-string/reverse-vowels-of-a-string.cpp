class Solution {
public:
bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
               c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }

    string reverseVowels(string s) {
        int n = s.length();
        int r = n-1;
        int l = 0;
        while(l<r){
            if(isVowel(s[l])){
                if(isVowel(s[r])){
                    swap(s[l],s[r]);
                    l++;
                    r--;
                }
                
                else {
                    r--;
                }
            }
            else {
                l++;
            }
        }
        return s;
    }
};