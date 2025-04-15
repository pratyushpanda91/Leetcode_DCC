#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums1.size(); i++) 
            mpp[nums1[i]] = i;
        
        ordered_set st;
        long long total = 0 , n = nums2.size();
        
        for (int i = 0; i < n; i++) {
            int idx = mpp[nums2[i]];    
            int left = st.order_of_key(idx); 
            int right = (n - 1 - idx) - (st.size() - left);
            total += (long long) left * right; 
            st.insert(idx);
        }
        return total;
    }
};
