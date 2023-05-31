#include <sstream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  string simplifyPath(string path) {
    vector<string> folds;
    path = path + "/";
    int last_mark = 0;
    string new_fold;
    for (int a = 0; a < path.size(); ++a) {
      if (path[a] == '/') {
        if (last_mark < a - 1) {
          new_fold = path.substr(last_mark + 1, a - last_mark - 1);
        } else {
          last_mark = a;
          continue;
        }
        last_mark = a;

        if (new_fold == "..") {
          if (!folds.empty())
            folds.pop_back();
        } else if (new_fold == "." || new_fold.size() == 0) {
          // do nothing
        } else {
          folds.push_back(new_fold);
        }
      }
    }
    stringstream ss;
    for (int a = 0; a < folds.size(); ++a) {
      ss << "/" << folds[a];
    }
    if (folds.size() == 0) {
      return "/";
    }

    return ss.str();
  }
};
