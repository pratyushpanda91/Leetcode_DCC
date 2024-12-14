class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;  // Total number of continuous subarrays
        int left = 0;         // Left pointer for the sliding window
        
        multiset<int> window; // To track min and max in the current window
        
        for (int right = 0; right < n; ++right) {
            // Add the current number to the window
            window.insert(nums[right]);
            
            // Check if the condition is violated
            while (*window.rbegin() - *window.begin() > 2) {
                // Remove the leftmost element from the window
                window.erase(window.find(nums[left]));
                ++left;  // Move the left pointer
            }
            
            // Count all valid subarrays ending at `right`
            total += (right - left + 1);
        }
        
        return total;
    }
};
