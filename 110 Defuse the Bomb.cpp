class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int s = code.size(), index, window = 0, pointer1, pointer2;
        vector<int> result;
        if (k == 0) {
            result.assign(s, 0);
            return result;
        }
        if (k > 0) {
            pointer1 = 1;
            pointer2 = k;
        } else if (k < 0) {
            pointer1 = s + k;
            pointer2 = s - 1;
        }
        for (index = pointer1; index < pointer2 + 1; index++)
            window = window + code[index];
        for (index = 0; index < s; index++) {
            result.push_back(window);
        
            window = window - code[pointer1++ % s] + code[++pointer2 % s];
        }
        return result;
    }
};
