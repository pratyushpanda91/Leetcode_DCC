class Solution {
private:
    static const int mod = 1e9 + 7;
    vector<vector<long long>> multiply(const vector<vector<long long>> &A, const vector<vector<long long>> &B) {
        vector<vector<long long>> C(3, vector<long long>(3, 0));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                long long sum = 0;
                for (int k = 0; k < 3; k++) {
                    sum = (sum + A[i][k] * B[k][j]) % mod;
                }
                C[i][j] = sum;
            }
        }
        return C;
    }

    vector<vector<long long>> power(vector<vector<long long>> base, long long exp) {
        vector<vector<long long>> result = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        while (exp > 0) {
            if (exp & 1) result = multiply(result, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return result;
    }

    public:
        int numTilings(int n) {
            if (n == 0) return 1;
            if (n == 1) return 1;
            if (n == 2) return 2;

            vector<vector<long long>> temp = {{2, 0, 1}, {1, 0, 0}, {0, 1, 0}};
            vector<vector<long long>> powered = power(temp, n - 2);
            long long answer = (powered[0][0] * 2 + powered[0][1] * 1 + powered[0][2] * 1) % mod;

            return answer;
        }
    };
