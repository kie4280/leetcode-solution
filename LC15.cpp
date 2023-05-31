class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3)
      return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int a = 0; a < nums.size() - 2; ++a) {
      if (a > 0 && nums[a] == nums[a - 1])
        continue;
      int left = a + 1, right = nums.size() - 1;
      while (left < right) {
        int sum = nums[a] + nums[left] + nums[right];
        if (sum < 0) {
          ++left;
        } else if (sum > 0) {
          --right;
        } else {
          result.push_back({nums[a], nums[left], nums[right]});
          --right;
          ++left;
          while (left < nums.size() && nums[left] == nums[left - 1]) {
            ++left;
          }
          while (right > 0 && nums[right] == nums[right + 1]) {
            --right;
          }
        }
      }
    }
    return result;
  }
};
