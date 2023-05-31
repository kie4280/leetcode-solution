#include <stack>
using namespace std;

class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> st;
    int p_index = 0;
    for (int a=0; a<pushed.size(); ++a) {
      st.push(pushed[a]);
      while (!st.empty() && popped[p_index] == st.top()) {
        st.pop();
        ++p_index;
      }
    }
    return st.empty();
  }
};
