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

int main() {
  ios_base::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> mat(n, vector<char>(m, '.'));
    vector<int> sumRow(n, 0);
    vector<int> sumCol(m, 0);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mat[i][j];
        if (mat[i][j] == '*') {
          sumRow[i]++;
          sumCol[j]++;
        }
      }
    }

    int ans = n * m + 2;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans = min(ans, (n - sumRow[i]) + (m - sumCol[j]) - (mat[i][j] == '.'));
      }
    }

    cout << ans << endl;
  }

  return 0;
}
