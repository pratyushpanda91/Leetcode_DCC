class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string t;
            for (size_t i = 0; i + 1 < s.size(); i++) {
                t += ((s[i] - '0' + s[i + 1] - '0') % 10) + '0';
            }
            s = t;
        }
        return s[0] == s[1];
    }
};
