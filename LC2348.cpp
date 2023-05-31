class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    long long longest = 0;
    long long sum = 0;
    for (auto i : nums) {
      if (i == 0) {
        ++longest;
      } else {
        if (longest > 0) {
          sum += longest * (longest + 1) / 2;
        }
        longest = 0;
      }
    }
    if (longest > 0) {
      sum += longest * (longest + 1) / 2;
    }
    return sum;
  }
};
