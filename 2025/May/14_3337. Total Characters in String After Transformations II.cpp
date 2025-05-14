class Solution {
    static const int K = 26;
    static const int MOD = 1000000007;

public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long> freq(K, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        vector<array<long long, K>> base(K);
        for (int i = 0; i < K; i++) {
            for (int k = 1; k <= nums[i]; k++) {
                base[i][(i + k) % K]++;
            }
        }
        auto mt = matrixPower(base, t);
        long long ans = 0;
        for (int i = 0; i < K; i++) {
            if (freq[i] == 0) continue;
            for (int j = 0; j < K; j++) {
                ans = (ans + freq[i] * mt[i][j]) % MOD;
            }
        }

        return (int)ans;
    }

private:
    using Mat = vector<array<long long, K>>;
    Mat matrixPower(Mat M, int exp) {
        Mat res(K);
        for (int i = 0; i < K; i++) {
            res[i][i] = 1;
        }
        Mat base = M;
        while (exp > 0) {
            if (exp & 1) {
                res = multiply(res, base);
            }
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }
    Mat multiply(const Mat& A, const Mat& B) {
        Mat C(K);
        for (int i = 0; i < K; i++) {
            for (int k = 0; k < K; k++) {
                long long aik = A[i][k];
                if (!aik) continue;
                for (int j = 0; j < K; j++) {
                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }
};
