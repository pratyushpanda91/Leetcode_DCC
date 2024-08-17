class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Note:
        // Initilly we have 0 points with us
        // Currently if we took the points at row 0 and col 2
        // We went to row 1 and took points at col 0 
        // Then our total points would be points[0][2] + points[1][0] - abs(0 - 2)
        // We need to find the maximum points that we can collect
        // Example 1
        // 1 2 3
        // 1 5 1
        // 3 1 1
        // First iteration
        // 1 2 3 -- -2 + 1, -1 + 2, 0 + 3
        // Considering for the second row
        // Penalitites : max(penality + prevRowScore)
        // 1 + 1 2 + 5  3 + 1 -- 7
        // 2 7 4
        // 3 1 1
        // This is recurrsive calls i.e. Performing the same operation on multiple sub problems (More clearly here different sub problems are considering the prev row and the current row)
        // Current row points = penalty : 0 + (r, c) points[r][c]
        // a b c d
        // x1 x2 x3 x4
        int rows = points.size();
        int cols = points[0].size();
        vector<long long> prevRow(cols, 0);
        for(int i = 0 ; i < cols ; i++){
            prevRow[i] = points[0][i];
        }
        for(int row = 0 ; row < rows - 1; row++){
            vector<long long> leftMax(cols, 0);
            vector<long long> rightMax(cols, 0);
            vector<long long> currRow(cols, 0);
            leftMax[0] = prevRow[0];
            for(int col = 1 ; col < cols ; col++){
                leftMax[col] = max(leftMax[col - 1] - 1, prevRow[col]);
            }
            rightMax[cols - 1] = prevRow[cols - 1];
            for(int col = cols - 2 ; col >= 0 ; col--){
                rightMax[col] = max(rightMax[col + 1] - 1, prevRow[col]);
            }
            for(int col = 0 ; col < cols ; col++){
                currRow[col] = max(leftMax[col], rightMax[col]) + points[row + 1][col];
            }
            prevRow = currRow;
        }
        long long ans = LONG_LONG_MIN;
        for(int i = 0 ; i < cols ; i++){
            ans = max(ans, prevRow[i]);
        }
        return ans;
    }
};
