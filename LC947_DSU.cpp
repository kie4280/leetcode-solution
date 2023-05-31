#include <vector>
#include <set>

using namespace std;
class Solution {
public:
  void DS_union(vector<int> &parent, int a, int b) {
    parent[DS_find(parent, b)] = DS_find(parent, a);
  }

  int DS_find(vector<int> &parent, int a) {
    if (parent[a] == a) return a;
    return parent[a] = DS_find(parent, parent[a]);
  }

  void DS_init(vector<int> &parent, int n) {
    parent.resize(n);
    for (int a=0; a<n; ++a) {
      parent[a] = a;
    }
  }

  int removeStones(vector<vector<int>> &stones) {
    vector<int> p;
    DS_init(p, stones.size());
    for (int a=0; a<stones.size(); ++a) {
      for (int b=a+1; b<stones.size(); ++b) {
        if (stones[a][0] == stones[b][0] || stones[a][1] == stones[b][1]) {
          DS_union(p, a, b);
        }
      }
    }
    set<int> st;
    for (int a=0; a<p.size(); ++a) {
      st.insert(DS_find(p, a));
    }
    return stones.size() - st.size();
  }
};
