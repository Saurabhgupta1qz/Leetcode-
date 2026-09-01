class Solution {
public:
    bool match(string word, string pattern) {
        unordered_map<char, char> mp1, mp2;

        for(int i = 0; i < word.size(); i++) {
            if(mp1.count(pattern[i]) && mp1[pattern[i]] != word[i])
                return false;

            if(mp2.count(word[i]) && mp2[word[i]] != pattern[i])
                return false;

            mp1[pattern[i]] = word[i];
            mp2[word[i]] = pattern[i];
        }

        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;

        for(string word : words) {
            if(match(word, pattern))
                ans.push_back(word);
        }

        return ans;
    }
};