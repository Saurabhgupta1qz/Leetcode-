class Solution {
public:
    bool checkString(string s) {
     string b = s;
     sort(s.begin(),s.end());
     return s==b;
    }
};