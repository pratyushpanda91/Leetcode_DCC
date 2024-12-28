class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n - k + 1); // Sum of subarrays of size k
        vector<int> left(n - k + 1), right(n - k + 1);
        vector<int> result(3);

        // Compute sums of all subarrays of size k
        int window_sum = accumulate(nums.begin(), nums.begin() + k, 0);
        sum[0] = window_sum;
        for (int i = 1; i <= n - k; ++i) {
            window_sum += nums[i + k - 1] - nums[i - 1];
            sum[i] = window_sum;
        }

        // Compute the best subarray index from the left
        int best = 0;
        for (int i = 0; i <= n - k; ++i) {
            if (sum[i] > sum[best]) {
                best = i;
            }
            left[i] = best;
        }

        // Compute the best subarray index from the right
        best = n - k;
        for (int i = n - k; i >= 0; --i) {
            if (sum[i] >= sum[best]) {
                best = i;
            }
            right[i] = best;
        }

        // Find the best combination of three subarrays
        int max_sum = 0;
        for (int mid = k; mid <= n - 2 * k; ++mid) {
            int l = left[mid - k];
            int r = right[mid + k];
            int total = sum[l] + sum[mid] + sum[r];
            if (total > max_sum) {
                max_sum = total;
                result = {l, mid, r};
            }
        }

        return result;
    }
};
