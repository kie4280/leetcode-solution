#include <vector>
#include <set>

using namespace std;
class Solution {
public:
  void dfs(vector<vector<int>> &sts, vector<bool> &visited, int n) {
    visited[n] = true;
    vector<int> &s = sts[n];
    for (int a=0; a<sts.size(); ++a) {
      if (!visited[a] && (s[0] == sts[a][0] || s[1] == sts[a][1])) {
        dfs(sts, visited, a);
      }
    }
  }
  int removeStones(vector<vector<int>> &stones) {
    vector<bool> visited(stones.size());
    int k = 0;
    for (int a=0; a<stones.size(); ++a) {
      if (!visited[a]) {
        ++k;
        dfs(stones, visited, a);
      }
    }
    return stones.size() - k;
  }
};
