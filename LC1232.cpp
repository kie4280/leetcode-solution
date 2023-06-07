class Solution {
public:
  bool checkStraightLine(vector<vector<int>> &coordinates) {
    bool same = true;
    int x0 = coordinates[0][0], y0 = coordinates[0][1];
    for (int a=0; a<coordinates.size()-1; ++a) {
      int x1 = coordinates[a][0], y1 = coordinates[a][1];
      int x2 = coordinates[a+1][0], y2 = coordinates[a+1][1];
      if ((y1-y0) * (x2-x0) != (y2-y0) * (x1-x0)) {
        same = false;
        break;
      }
    }
    return same;
  }
};
