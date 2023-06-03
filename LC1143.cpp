class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> table(n+1, vector<int>(m+1, 0));
    for (int a=1; a<=n; ++a) {
      for (int b=1; b<=m; ++b) {
        if (text1[a-1] == text2[b-1]) {
          table[a][b] = table[a-1][b-1]+1;
        } else {
          table[a][b] = max(table[a-1][b], table[a][b-1]);
        }
      }
    }
    return table[n][m];
    
  }
};
