class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(prices); // Initialize result with original prices
        stack<int> st; // Stack to store indices

        for (int i = 0; i < n; i++) {
            // Check for discounts for indices in the stack
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                int idx = st.top();
                st.pop();
                result[idx] = prices[idx] - prices[i]; // Apply discount
            }
            st.push(i); // Push current index onto the stack
        }

        return result;
    }
};
