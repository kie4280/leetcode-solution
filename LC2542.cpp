#include <vector>
#include <queue>
#include <algorithm>
#include <array>

using namespace std;
class Solution {
public:
  long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
    int n = nums1.size();
    vector<array<int, 2>> sorted(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int a=0; a<n; ++a) {
      sorted.push_back({nums1[a], nums2[a]});
    }
    
    auto cmp = [](const auto &a, const auto &b) {
      return a[1] > b[1];
    };
    sort(sorted.begin(), sorted.end(), cmp);
    long long sum = 0;
    int counter = 0;
    long long maxx = -1;
    for (int a=0; a<n; ++a) {
      sum += sorted[a][0];
      pq.push(sorted[a][0]);
      if (counter == k-1) {
        --counter;
        maxx = max(maxx, sum * sorted[a][1]);
        sum -= pq.top();
        pq.pop();
      }
      ++counter;
    }
    return maxx;
  }
};
