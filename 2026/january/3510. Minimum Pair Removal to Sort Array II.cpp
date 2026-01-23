#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return 0;
        
        vector<long long> vals(nums.begin(), nums.end());
        vector<int> nexts(n), prevs(n);
        vector<bool> removed(n, false);
        
        vector<pair<long long, int>> pq_container;
        pq_container.reserve(3 * n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq(
            greater<pair<long long, int>>(), move(pq_container));
        
        int unsorted_cnt = 0;
        
        for (int i = 0; i < n; ++i) {
            prevs[i] = i - 1;
            nexts[i] = i + 1;
        }
        nexts[n-1] = -1;
        
        for (int i = 0; i < n - 1; ++i) {
            unsorted_cnt += (vals[i] > vals[i + 1]);
            pq.emplace(vals[i] + vals[i + 1], i);
        }
        
        if (unsorted_cnt == 0) return 0;
        
        int moves = 0;
        
        while (unsorted_cnt > 0) {
            auto [sum, u] = pq.top();
            pq.pop();
            
            if (removed[u]) continue;
            int v = nexts[u];
            if (v == -1 || removed[v]) continue;
            if (vals[u] + vals[v] != sum) continue;
            
            int p = prevs[u];
            int next_v = nexts[v];
            
            ++moves;
            
            if (p != -1 && vals[p] > vals[u]) --unsorted_cnt;
            if (vals[u] > vals[v]) --unsorted_cnt;
            if (next_v != -1 && vals[v] > vals[next_v]) --unsorted_cnt;
            
            vals[u] = sum;
            nexts[u] = next_v;
            if (next_v != -1) prevs[next_v] = u;
            removed[v] = true;
            
            if (p != -1 && vals[p] > vals[u]) ++unsorted_cnt;
            if (next_v != -1 && vals[u] > vals[next_v]) ++unsorted_cnt;
            
            if (unsorted_cnt == 0) break;
            
            if (p != -1) pq.emplace(vals[p] + vals[u], p);
            if (next_v != -1) pq.emplace(vals[u] + vals[next_v], u);
        }
        
        return moves;
    }
};
