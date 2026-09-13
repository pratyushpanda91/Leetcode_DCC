class Solution {
    public int[][] cyclicShift(int n, int[][] grid, int[] rowShift, int[] colShift) {
        int[][] temp = new int[n][n];
        for(int i = 0; i<n; i++){
            int shift = rowShift[i] % n;
            for(int j = 0; j < n; j++){
                temp[i][j] = grid[i][(j + shift) % n];
            }
        }
        int[][] ans = new int[n][n];
        for(int j = 0; j < n; j++){
            int shift = colShift[j] % n;

            for(int i = 0; i<n;i++){
                ans[i][j] = temp[(i + shift) % n][j];
            }
        }
        return ans;
    }
}