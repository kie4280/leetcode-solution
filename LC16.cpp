class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int minn = 1000000;
    sort(nums.begin(), nums.end());
    for (int a=0; a<nums.size() - 2; ++a) {
      int l=a+1, r=nums.size()-1;
      while (l<r) {
        int sum = nums[a]+nums[l]+nums[r];
        int offset = sum-target; 
        if (abs(offset) < abs(minn-target)) minn = sum;
        if (offset < 0) {
          ++l;
        } else if (offset > 0) {
          --r;
        } else {
          return target; 
        }
         
      }
    }
    return minn;
  }
};
