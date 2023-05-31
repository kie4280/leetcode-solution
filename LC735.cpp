class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    vector<int> res;
    for (auto i : asteroids) {
      bool neg_exist = true;
      while (i < 0 && res.size() > 0) {
        int p = res.back();
        if (p < 0) break;
        if (abs(i) >= p) {
          res.pop_back();
        }
        if (i+p >= 0) {
          neg_exist = false;
          break;
        }
      }
      if (i > 0 || (i < 0 && neg_exist))
        res.push_back(i);
    }
    return res;
  }
};
