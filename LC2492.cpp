class Solution {
public:
  vector<int> shortest;
  void union_(vector<int> &arr, int a1, int a2) {
    int f1 = find(arr, a2), f2 = find(arr, a1);
    int s = min(shortest[f1], shortest[f2]);
    arr[f2] = f1;
    shortest[f1] = s;
  }

  int find(vector<int> &arr, int n) {
    if (arr[n] == n)
      return n;
    return arr[n] = find(arr, arr[n]);
  }
  int minScore(int n, vector<vector<int>> &roads) {
    vector<int> parent;
    shortest.resize(n, 100000);
    for (int a = 0; a < n; ++a) {
      parent.emplace_back(a);
    }
    for (auto &r : roads) {
      int n1 = r[0] - 1, n2 = r[1] - 1, d = r[2];
      union_(parent, n1, n2);
      int f = find(parent, n1);
      shortest[f] = min(shortest[f], d);
    }
    return shortest[find(parent, n - 1)];
  }
};
