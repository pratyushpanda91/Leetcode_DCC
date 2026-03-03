class Solution {
public:
    char findKthBit(int n, int k) {
        vector<int> noda(n);
        noda[0] = 1;
        for (int i = 1; i < n; i++) {
            noda[i] = 2 * noda[i - 1] + 1;
        }
        return findDigit(k - 1, n - 1, noda);
    }

private:
    char findDigit(int i, int n, vector<int>& noda) {
        if (n == 0) {
            return '0';
        }
        int mid = (noda[n] - 1) / 2;
        if (i == mid) {
            return '1';
        } else if (i < mid) {
            return findDigit(i, n - 1, noda);
        } else {
            return findDigit(mid - (i - mid), n - 1, noda) == '0' ? '1' : '0';
        }
    }
};
