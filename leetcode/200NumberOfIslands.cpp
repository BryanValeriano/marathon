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
  void dfs(vector<vector<char>> &grid, int i, int j) {
    if (i >= grid.size())
      return;
    if (j >= grid[i].size())
      return;
    if (grid[i][j] != '1')
      return;

    int mov[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    grid[i][j] = 'x';
    for (int k = 0; k < 4; k++) {
      int ii = i + mov[k][0];
      int jj = j + mov[k][1];
      dfs(grid, ii, jj);
    }
  }

  int numIslands(vector<vector<char>> &grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == '1') {
          dfs(grid, i, j);
          ans++;
        }
      }
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);

  return 0;
}
