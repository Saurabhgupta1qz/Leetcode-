class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int cnt = 0;

        for(char c : word) {
            if(isupper(c))
                cnt++;
        }

        if(cnt == 0 || cnt == n)
            return true;

        if(cnt == 1 && isupper(word[0]))
            return true;

        return false;
    }
};