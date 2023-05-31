class Solution {
public:
  void set_union(vector<int> &parents, int a1, int a2) {
    parents[set_find(parents, a2)] = set_find(parents, a1);
  }

  int set_find(vector<int> &parents, int n) {
    if (parents[n] == n)
      return n;
    return parents[n] = set_find(parents, parents[n]);
  }

  int makeConnected(int n, vector<vector<int>> &connections) {
    if (connections.size() < n - 1)
      return -1;
    vector<int> parents(n);
    for (int a=0; a<n; ++a) {
      parents[a] = a;
    }
    for (auto &con : connections) {
      set_union(parents, con[0], con[1]);

    }
    set<int> par_set;
    for (int a=0; a<n; ++a) {
      int f = set_find(parents, parents[a]);
      par_set.insert(f);
       
    }
    return par_set.size() - 1;
  }
};
