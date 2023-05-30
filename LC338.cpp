#include <vector>

using namespace std;
class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> r(n+1);
    for (int a=0; a<=n; ++a) {
      int sum = 0;
      int tmp = a;
      for (int b=0; b<31; ++b) {
        sum += tmp & 1;
        tmp = tmp >> 1;
      }
      r[a] = sum;
    }
    return r;
  }
};
