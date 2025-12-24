class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& cap) {
        int sum = accumulate(apple.begin(), apple.end(), 0);
        uint8_t fq[51] = {};
        int high = 0, low = 51;
        for (auto& c : cap) {
            fq[c]++;
            high = max(high, c);
            low = min(low, c);
        }

        int res = 0;
        for (int i = high; i >= low && sum > 0; i--) {
            while (fq[i]-- > 0 && sum > 0) {
                sum -= i;
                res++;
            }
        }

        return res;
    }
};
