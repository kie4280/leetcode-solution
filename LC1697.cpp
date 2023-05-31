#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  void DS_union(vector<int> &parent, int a, int b) {
    parent[DS_find(parent, b)] = DS_find(parent, a);
  }

  int DS_find(vector<int> &parent, int a) {
    if (parent[a] == a)
      return a;
    return parent[a] = DS_find(parent, parent[a]);
  }

  vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList,
                                         vector<vector<int>> &queries) {
    sort(edgeList.begin(), edgeList.end(),
         [](const auto &a, const auto &b) { return a[2] < b[2]; });
    for (int a = 0; a < queries.size(); ++a) {
      queries[a].push_back(a);
    }
    sort(queries.begin(), queries.end(),
         [](const auto &a, const auto &b) { return a[2] < b[2]; });
    vector<bool> results(queries.size());
    vector<int> ds(n);
    for (int a = 0; a < n; ++a) {
      ds[a] = a;
    }
    int b = 0;
    for (auto &q : queries) {
      for (; b < edgeList.size() && edgeList[b][2] < q[2]; ++b) {
        DS_union(ds, edgeList[b][0], edgeList[b][1]);
      }
      results[q[3]] = (DS_find(ds, q[0]) == DS_find(ds, q[1]));
    }
    return results;
  }
};
