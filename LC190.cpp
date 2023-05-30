class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t out;
    for (int a = 0; a < 31; ++a) {
      out += n & 1;
      n = n >> 1;
      out = out << 1;
    }
    out += n & 1;
    return out;
  }
};
