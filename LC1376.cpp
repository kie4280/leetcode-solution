#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
  int search(int n, const vector<int> &manager, const vector<int> &informTime, vector<int> &time) {

    if (manager[n] == -1) return 0;
    int m = manager[n];
    int t = informTime[m];
    if (time[m] < 0) {
      t += search(m, manager, informTime, time);
    } else {
      t += time[m];
    }

    return time[n] = t;
  }

  int numOfMinutes(int n, int headID, vector<int> &manager,
                   vector<int> &informTime) {
    vector<int> time(n, -1);
    time[headID] = 0;
    int maxx = -1;
    for (int a=0; a<n; ++a) {
      maxx = max(maxx, search(a, manager, informTime, time));
    }
    return maxx;
  }
};
