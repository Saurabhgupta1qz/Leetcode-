// class Solution {
// public:
//     vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
//         vector<int>res;
//         for(int i = 0; i<queryIndices.size();i++){
//                 int idx = queryIndices[i];
//             char ch = queryCharacters[i];

//             s[idx] = ch;
//             int len = 1;
//             int ans = 1;
//             for(int j = 1; j<s.size();j++){
//                 if(s[j]==s[j-1]) len++;
//                 else len = 1;
//                 ans = max(ans,len);
//             }

//            res.push_back(ans);
//         }
//         return res;
//     }
// };

class Solution {
    struct Node {
        char lc, rc;
        int pre, suf, mx, len;
    };

    vector<Node> st;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node c;
        c.len = a.len + b.len;
        c.lc = a.lc;
        c.rc = b.rc;

        c.pre = a.pre;
        c.suf = b.suf;
        c.mx = max(a.mx, b.mx);

        if (a.rc == b.lc) {
            c.mx = max(c.mx, a.suf + b.pre);

            if (a.pre == a.len)
                c.pre = a.len + b.pre;

            if (b.suf == b.len)
                c.suf = b.len + a.suf;
        }

        return c;
    }

    void build(int p, int l, int r, string &s) {
        if (l == r) {
            st[p] = {s[l], s[l], 1, 1, 1, 1};
            return;
        }

        int m = (l + r) / 2;

        build(2 * p, l, m, s);
        build(2 * p + 1, m + 1, r, s);

        st[p] = merge(st[2 * p], st[2 * p + 1]);
    }

    void update(int p, int l, int r, int idx, char ch) {
        if (l == r) {
            st[p] = {ch, ch, 1, 1, 1, 1};
            return;
        }

        int m = (l + r) / 2;

        if (idx <= m)
            update(2 * p, l, m, idx, ch);
        else
            update(2 * p + 1, m + 1, r, idx, ch);

        st[p] = merge(st[2 * p], st[2 * p + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        int n = s.size();

        st.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, idx, ch);

            ans.push_back(st[1].mx);
        }

        return ans;
    }
};