#include <array>

using namespace std;
class Solution {
public:
  int garbageCollection(vector<string> &garbage, vector<int> &travel) {
    array<char, 3> type = {'G', 'P', 'M'};
    int sum = 0;
    for (int a = 0; a < 3; ++a) {
      int last_pos = 0;
      for (int b=0; b<garbage.size(); ++b) {
        const string &s = garbage[b];
        int gsum = 0;
        for (auto &c : s) {
          if (c == type[a]) {
            ++gsum;
          }
        }
        sum += gsum;
        if (gsum > 0) {
          last_pos = b;
        }
      }
      for (int c=1; c<=last_pos; ++c) {
        sum += travel[c-1];
      }
    }
    return sum;
  }
};
