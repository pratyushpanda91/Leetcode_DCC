class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxS = s, minS = s;
        char toReplaceMax = ' ';
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        for (char &c : maxS) {
            if (c == toReplaceMax) c = '9';
        }
        char toReplaceMin = s[0];
        for (char &c : minS) {
            if (c == toReplaceMin) c = '0';
        }
        return stoi(maxS) - stoi(minS);
    }
};
