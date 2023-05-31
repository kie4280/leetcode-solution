class Solution {
public:
  long long getDescentPeriods(vector<int> &prices) {
    long long sum = 0;
    int prev_p = -1;
    long long accum = 1;
    for (auto i:prices) {
      if (prev_p != -1) {
        if (prev_p == i+1) {
          ++accum;
        } else {
          sum += accum * (accum+1) / 2;
          accum = 1;
        }
      }
      prev_p = i;
    }
    sum += accum * (accum+1) / 2;
    return sum;
  }
};
