#define MAX_COINS 100000

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> arr(amount+1, MAX_COINS);
    arr [0] = 0;
    for (int a=1; a<=amount; ++a) {
      for (int b=0; b<coins.size(); ++b) {
        int c = coins[b];
        if (c <= a && arr[a-c] != -1) {
          arr[a] = min(arr[a], arr[a-c] + 1);
        }
      }
      if (arr[a] == MAX_COINS) arr[a] = -1;
    }
    return arr[amount];
  }
};
