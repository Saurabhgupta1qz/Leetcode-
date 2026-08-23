class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int l = 0, r = 0, ql = 0, qr = 0;

        for(int i = 0; i < n / 2; i++) {
            if(num[i] == '?') ql++;
            else l += num[i] - '0';
        }

        for(int i = n / 2; i < n; i++) {
            if(num[i] == '?') qr++;
            else r += num[i] - '0';
        }

        int q = ql - qr;
        int diff = l - r;

        if(q % 2 != 0)
            return true;

        return diff + (q / 2) * 9 != 0;
    }
};