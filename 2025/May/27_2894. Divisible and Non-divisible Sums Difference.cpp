class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum = n * (n + 1) / 2;
        int divisibleCount = n / m;
        int divisibleSum = m * divisibleCount * (divisibleCount + 1) / 2;
        return totalSum - 2 * divisibleSum;
    }
};
