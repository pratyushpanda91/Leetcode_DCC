class Solution {
public:
  bool hasValidPath(vector<vector<int>>& grid) {
    int m = size(grid);
    int n = size(grid.front());
    if (m == 1 && n == 1) return true;

    if (n > 1 && connects_east(grid[0][0]) && connects_west(grid[0][1]) &&
        can_reach_end(grid, 0, 1, Prev::west)) {
      return true;
    }

    if (m > 1 && connects_south(grid[0][0]) && connects_north(grid[1][0]) &&
        can_reach_end(grid, 1, 0, Prev::north)) {
      return true;
    }

    return false;
  }

private:

  enum class Prev { north, east, south, west };

  static bool can_reach_end(vector<vector<int>>& grid, int i, int j, Prev prev) {
    int m = size(grid);
    int n = size(grid.front());

    while (true) {

      if (i == m  - 1 && j == n - 1) return true;
      if (i == 0 && j == 0) return false;
      auto road = grid[i][j];
      if (i > 0 && prev != Prev::north && connects_north(road) &&
          connects_south(grid[i - 1][j])) {
        --i;
        prev = Prev::south;
      } else if (j > 0 && prev != Prev::west && connects_west(road) &&
                 connects_east(grid[i][j - 1])) {
        --j;
        prev = Prev::east;
      } else if (i < m - 1 && prev != Prev::south && connects_south(road) &&
                 connects_north(grid[i + 1][j])) {
        ++i;
        prev = Prev::north;
      } else if (j < n - 1 && prev != Prev::east && connects_east(road) &&
                 connects_west(grid[i][j + 1])) {
        ++j;
        prev = Prev::west;
      } else {
        return false;
      }
    }
  }

  static bool connects_north(int road) {
    return road == 2 || road == 5 || road == 6;
  }

  static bool connects_south(int road) {
    return road == 2 || road == 3 || road == 4;
  }

  static bool connects_west(int road) {
    return road == 1 || road == 3 || road == 5;
  }

  static bool connects_east(int road) {
    return road == 1 || road == 4 || road == 6;
  }
};
