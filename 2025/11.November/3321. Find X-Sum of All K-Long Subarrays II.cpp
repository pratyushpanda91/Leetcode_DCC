class Solution {
public:
    bool isSquare(int n) {
        int s = sqrt(n);
        return s * s == n;
    }

    bool isSumOfTwoSquares(int n) {
        for (int i = 1; i * i <= n; ++i) {
            if (isSquare(n - i * i)) return true;
        }
        return false;
    }

    void reduce(int& n) {
        while (n % 4 == 0) n /= 4;
    }

    int minSquares(int n) {
     
        if (isSquare(n)) return 1;

        if (isSumOfTwoSquares(n)) return 2;

        int temp = n;
        reduce(temp);
        if (temp % 8 == 7) return 4;

        return 3;
    }
};
