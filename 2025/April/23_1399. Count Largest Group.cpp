class Solution {
public:
    int countLargestGroup(int n, int maxi = 0, int count = 0) {
        unordered_map <int,int> mpp;
        for (int i = 1 ; i <= n ; i++) {
            int x = digsum(i);
            maxi = max(maxi, ++mpp[x]);
        }
        for (auto& p : mpp) if (p.second == maxi) ++count;
        return count;
    }
    int digsum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};
