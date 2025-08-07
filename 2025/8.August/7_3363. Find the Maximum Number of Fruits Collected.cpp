class Solution {
    using ll = long long;
    static constexpr int INF = std::numeric_limits<int>::max();

    // DFS + Memoization
    int dfs(const vector<vector<int>>& fruits,
            int row, int col, int moves,
            vector<vector<int>>& mem,
            const vector<pair<int,int>>& dirs)
    {
        int n = fruits.size();
        if (row == n-1 && col == n-1)   //Reached target cell
            return moves == 0 ? 0 : INF;
        if (moves == 0 || row == col)   //Move NOT-allowed
            return INF;
        if (mem[row][col] != -1)        //Repeating Sub-problem
            return mem[row][col];

        ll max_fruits = -1;
        for (auto [delta_row, delta_col] : dirs) {
            int new_row = row + delta_row;
            int new_col = col + delta_col;
            if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < n) {//Boundary check
                int val = dfs(fruits, new_row, new_col, moves-1, mem, dirs);
                if (val != INF)
                    max_fruits = max(max_fruits, (ll)val);
            }
        }
        return mem[row][col] = (max_fruits < 0 ? INF : fruits[row][col] + max_fruits);
    }

public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();

        // Step-1: Collect fruits in the main diagonal
        ll first = 0;
        for (int i = 0; i < n; ++i)
            first += fruits[i][i];

        // Step-2: (2nd path: from top-right corner) only down-left/down/down-right
        vector<pair<int,int>> down_dirs = {{1,-1},{1,0},{1,1}};
        vector<vector<int>> mem(n, vector<int>(n, -1));
        int second = dfs(fruits, 0, n-1, n-1, mem, down_dirs);

        // 3) third path: only up-right/right/down-right
        vector<pair<int,int>> right_dirs = {{-1,1},{0,1},{1,1}};
        for (auto& row : mem) fill(row.begin(), row.end(), -1);
        int third = dfs(fruits, n-1, 0, n-1, mem, right_dirs);

        return first + second + third;
    }
};
