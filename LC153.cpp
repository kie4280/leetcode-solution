class Solution {
public:
  int findMin(vector<int> &nums) {
    int maxx = -1000000;
    int l = 0, r = nums.size() - 1;
    if (nums[l] < nums[r]) return nums[0];
    
    while (l < r) {
      int mid = (l+r) / 2;
      if (nums[mid] >= nums[l] && nums[mid] > maxx) {
        l = mid + 1;
      } 
      if (nums[mid] < nums[r]) {
        r = mid;
      }
      maxx = max(nums[mid], maxx);

    }
    return nums[l];
  }
};
