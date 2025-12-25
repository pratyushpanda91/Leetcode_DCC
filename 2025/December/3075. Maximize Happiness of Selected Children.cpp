class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // Find row index of max element in mid column
            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid])
                    maxRow = i;
            }

            int left  = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1e9;
            int right = (mid + 1 < m) ? mat[maxRow][mid + 1] : -1e9;

            if (mat[maxRow][mid] >= left && mat[maxRow][mid] >= right) {
                return {maxRow, mid};
            }
            else if (left > mat[maxRow][mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return {-1, -1}; // never reached
    }
};
