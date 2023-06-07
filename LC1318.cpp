class Solution {
public:
  inline int get_bit(int num, int i) { return (num >> i) & 1; }
  int minFlips(int a, int b, int c) {
    int sum = 0;
    int r = a | b;
    for (int i = 0; i < sizeof(int) * 8; ++i) {
      int r0 = r & 1, c0 = c & 1;
      if (r0 != c0) {
        if (c0 == 1) {
          ++sum;
        } else {
          sum += get_bit(a, i) + get_bit(b, i);
        }
      }
      r = r >> 1;
      c = c >> 1;
    }
    return sum;
  }
};
