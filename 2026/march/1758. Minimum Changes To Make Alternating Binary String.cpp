class Solution {
public:
    int minOperations(string s) {
        int count = 0, n = s.length();
        for (int i = 0; i < n; i++)
            count += (s[i] ^ i) & 1;
          
        return min(count, n - count);
    }
};
