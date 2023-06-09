class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    int sum = 0;
    int m = grid.size(), n = grid[0].size();
    int steps = 0;
    for (int a=m-1; a >= 0; --a) {
      while (steps < n && grid[a][steps] >= 0) {
        ++steps;
      }
      sum += n - steps;
    }
    return sum;
  }
};
