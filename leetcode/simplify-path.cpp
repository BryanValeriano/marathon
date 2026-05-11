#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x) cout << #x << " = " << x << endl
#define ok cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

class Solution {
public:
  vector<string> split(string &s, char d) {
    string x;
    vector<string> dirs;
    for (char c : s) {
      if (c == d) {
        if (x.size()) {
          dirs.push_back(x);
          x = "";
        }
      } else {
        x += c;
      }
    }
    if (x.size()) {
      dirs.push_back(x);
    }
    return dirs;
  }

  string vecToPath(vector<string> &currentPath) {
    string path;
    for (string dir : currentPath) {
      path += "/" + dir;
    }
    if (path.length() == 0)
      path = "/";
    return path;
  }

  string simplifyPath(string path) {
    vector<string> dirs = split(path, '/');
    vector<string> currentPath;
    for (string dir : dirs) {
      if (dir == "..") {
        if (currentPath.size() > 0)
          currentPath.pop_back();
      } else if (dir != ".") {
        currentPath.push_back(dir);
      }
    }
    return vecToPath(currentPath);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  Solution *solution;
  cout << solution->simplifyPath("/.../a/../b/c/../d/./") << endl;

  return 0;
}
