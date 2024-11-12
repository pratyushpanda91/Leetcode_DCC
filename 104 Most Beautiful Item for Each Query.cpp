class Solution {
public:
    int search(const vector<pair<int, int>>& v, int q) {
        int l = 0, r = v.size() - 1;
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[mid].first <= q) {
                ans = v[mid].second;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> res;
        sort(items.begin(), items.end());
        int n = items.size();
        int maxx = INT_MIN;
        vector<pair<int, int>> beauty;
        for (int i = 0; i < n; i++) {
            maxx = max(maxx, items[i][1]);
            beauty.push_back({items[i][0], maxx});
        }
        for (auto it : queries) {
            res.push_back(search(beauty, it));
        }
        return res;
    }
};
