class Solution {
public:
  const int MAX = 1000000;
  bool checkfit(vector<int> &weights, int days, int cap) {
    int ships = 0;
    int sum = 0;
    for (const auto &i:weights) {
      sum += i;
      if (sum > cap) {
        ++ships;
        sum = i;
      }
    }
    
    ++ships;
    return ships <= days;
  }
  int shipWithinDays(vector<int> &weights, int days) {
    int max_w = 0;
    int sum = 0;
    for (auto &i:weights) {
      sum += i;
      max_w = max(max_w, i);
    }
    int left = max_w;
    int right = sum;
    while (left < right) {
      int mid = (left + right) / 2;
      if (checkfit(weights, days, mid)) {
        right = mid;
      } else {
        left = mid+1;
      }
    }
    return left;

  }
};
