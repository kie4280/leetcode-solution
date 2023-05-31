#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
  int maxTwoEvents(vector<vector<int>> &events) {
    vector<vector<int>> unmatched;
    sort(events.begin(), events.end(),
         [](const auto &a, const auto &b) { return a[0] < b[0]; });
    int max_val = -1;

    return max_val;
  }
};
