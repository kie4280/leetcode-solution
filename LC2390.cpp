#include <string>

using namespace std;
class Solution {
public:
  string removeStars(string s) {
    int sp = 0;
    for (int a = 0; a < s.size(); ++a) {
      if (s[a] != '*') {
        s[sp++] = s[a];
      } else if (sp > 0) {
        --sp;
      }
    }
    s.erase(sp); 
    return s;
  }
};
