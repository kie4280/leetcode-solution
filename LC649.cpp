#include <queue>
#include <string>

using namespace std;
class Solution {
public:
  string predictPartyVictory(string senate) {
    queue<int> R,D;
    int n = senate.size();
    for (int a=0; a<n; ++a) {
      if (senate[a] == 'R') {
        R.push(a);
      } else {
        D.push(a);
      }
    }
    while (!R.empty() && !D.empty()) {
      int top_r = R.front(), top_d = D.front();
      if (top_r < top_d) {
        R.push(top_r+n);
      } else {
        D.push(top_d+n);
      }
      R.pop();
      D.pop();
    }
    if (!R.empty()) {
      return "Radiant";
    } else {
      return "Dire";
    }
  }
};
