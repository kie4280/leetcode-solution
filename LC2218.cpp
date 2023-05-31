#include <vector>
using namespace std;

class Solution {
public:
  int maxValueOfCoins(vector<vector<int>> &piles, int k) {
    int n = piles.size();
    vector<int> vt(k+1, 0);
    vector<int> vt_prev(k+1, 0);
    int sum = 0;
    vt[0] = 0;
    vt_prev[0] = 0;
    for (int a = 0; a < k && a < piles[0].size(); ++a) {
      sum += piles[0][a];
      vt_prev[a+1] = sum;
    }
    for (int a = 1; a < n; ++a) {
      for (int b=1; b<piles[a].size(); ++b) {
        piles[a][b] = piles[a][b-1] + piles[a][b];
      }
      for (int b = 1; b <= k; ++b) {
        int maxx = vt_prev[b];
        for (int c = 0; c < b && c < piles[a].size(); ++c) {
          maxx = max(maxx, vt_prev[b-c-1] + piles[a][c]);
        }
        vt[b] = maxx;
      }
      vt.swap(vt_prev);
    }
    return vt_prev[k];
  }
};
