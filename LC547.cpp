#include <vector>
#include <set>

using namespace std;
class Solution {
public:
  void set_union(vector<int> &parent, int a, int b) {
    int a_p = set_find(parent, a);
    int b_p = set_find(parent, b);
    if (a_p < b_p) {
      parent[b_p] = a_p;
    } else {
      parent[a_p] = b_p;
    }
  }
  int set_find(vector<int> &parent, int a) {
    if (parent[a] == a) return a;
    return parent[a] = set_find(parent, parent[a]);
  }
  int findCircleNum(vector<vector<int>> &isConnected) {
    int maxx = -1;
    int n = isConnected.size();
    vector<int> parent;
    for (int a=0; a<n; ++a) {
      parent.push_back(a);
    }
    for (int a=0; a<n; ++a) {
      for (int b=a+1; b<n; ++b) {
        if (isConnected[a][b]) {
          set_union(parent, a, b);
        }
      }
    }
    set<int> st;
    for(int a=0; a<n; ++a) {
      st.insert(set_find(parent, a));
    }
    return st.size();
  }
};
