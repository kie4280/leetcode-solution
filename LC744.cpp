class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    int l = 0, r = letters.size();
    int t = target;
    while (l < r) {
      int mid = (r+l)/2;
      if ((int)letters[mid] - t <= 0) {
        l = mid+1;
      } else {
        r = mid;
      }
    }
    if (l >= letters.size()) {
      return letters[0];
    } else {
      return letters[l];
    }
  }
};
