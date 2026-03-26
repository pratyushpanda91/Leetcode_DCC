#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int exists[100001];
int timer = 0;

static const int __ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
    bool solve(const vector<vector<int>>& grid, bool horizontal, bool forward) {
        int m = grid.size();
        int n = grid[0].size();
        int R = horizontal ? m : n;
        int C = horizontal ? n : m;

        vector<long long> lineSums(R, 0);
        long long totalSum = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                lineSums[horizontal ? i : j] += grid[i][j];
                totalSum += grid[i][j];
            }
        }

        long long s1 = 0;
        timer++; 

        for (int i = 0; i < R - 1; ++i) {
            int idx = forward ? i : (R - 1 - i);
            s1 += lineSums[idx];
            
            if (horizontal) {
                for (int j = 0; j < n; ++j) exists[grid[idx][j]] = timer;
            } else {
                for (int j = 0; j < m; ++j) exists[grid[j][idx]] = timer;
            }

            long long s2 = totalSum - s1;
            if (s1 == s2) return true;

            if (s1 > s2) {
                long long diff = s1 - s2;
                if (diff <= 100000 && exists[diff] == timer) {
                    
                    int cur_m = horizontal ? (i + 1) : m;
                    int cur_n = horizontal ? n : (i + 1);
                    
                    if (cur_m > 1 && cur_n > 1) {
                        
                        return true;
                    } else {
                    
                        if (cur_m == 1) {
                            int left_col = forward ? 0 : 0; 
                            int right_col = forward ? i : (n - 1); 
                            if (horizontal) {
                                if (grid[idx][0] == diff || grid[idx][n-1] == diff) return true;
                            } else { 
                                int start = forward ? 0 : (n - 1 - i);
                                int end = forward ? i : (n - 1);
                                if (grid[0][start] == diff || grid[0][end] == diff) return true;
                            }
                        } else { 
                            if (horizontal) { 
                                int start = forward ? 0 : (m - 1 - i);
                                int end = forward ? i : (m - 1);
                                if (grid[start][0] == diff || grid[end][0] == diff) return true;
                            } else { 
                                if (grid[0][idx] == diff || grid[m-1][idx] == diff) return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if (solve(grid, true, true)) return true;
        if (solve(grid, true, false)) return true;
        if (solve(grid, false, true)) return true;
        if (solve(grid, false, false)) return true;
        return false;
    }
};
