#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  int maxVowels(string s, int k) {
    int n = s.size();
    vector<int> prefix(n + 1, 0);
    int vs = 0;
    for (int a = 0; a < n; ++a) {
      char c = s[a];
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        ++vs;
      }
      prefix[a + 1] = vs;
    }
    int maxx = 0;
    
    for (int a = 0; a < n - k + 1; ++a) {
      maxx = max(maxx, prefix[a+k] - prefix[a]); 
    }
    return maxx;
  }
};
