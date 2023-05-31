#include <array>
using namespace std;

class Solution {
public:
  int minSteps(int n) {
    array<int, 1001> dp;
    dp[1] = 0;
    for (int a=2; a<=1000; ++a) {
      dp[a] = a;
    }
    for (int a=2; a<32; ++a) {
      for (int t=2; a*t <= 1000; ++t) {
        const int m = a*t;
        dp[m] = min(dp[m], dp[a] + t);
      }
    }
    return dp[n];
  }
};
