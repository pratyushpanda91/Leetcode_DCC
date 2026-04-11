class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        for (auto &it : mp) {
            auto &v = it.second;
            int m = v.size();
            
            if (m < 3) continue;
            
            for (int i = 0; i + 2 < m; i++) {
                int dist = v[i + 2] - v[i];
                ans = min(ans, 2 * dist);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
