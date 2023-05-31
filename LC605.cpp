class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    int len = flowerbed.size();
    for (int a=0; a<len; ++a) {
      if (flowerbed[a] || (a-1>=0 && flowerbed[a-1]) || (a+1<len && flowerbed[a+1])) continue;
      --n;
      flowerbed[a] = 1;
    }
    return n <= 0;
  }
};
