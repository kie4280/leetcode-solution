#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> dp;
  int solve(string &s, int start, int end) {
    if (dp[start][end] != -1) {
      return dp[start][end];
    }
    if (start == end)
      return dp[start][end] = 1;
    if (start > end)
      return dp[start][end] = 0;
    if (s[start] == s[end]) {
      return dp[start][end] = 2 + solve(s, start + 1, end - 1);
    }
    int left_delete = solve(s, start + 1, end);
    int right_delete = solve(s, start, end - 1);
    return dp[start][end] = max(left_delete, right_delete);
  }
  int longestPalindromeSubseq(string s) {
    dp.resize(1001, vector<int>(1001, -1));
    return solve(s, 0, s.size() - 1);
  }
};
