#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vector<vector<int>>> dp;
const int INF = 0x3f3f3f3f;

int solve(int l, int r, bool init, string &s, dp &memo) {
  if (l > r)
    return 0;

  int &x = memo[l][r][init];
  if (x != -1)
    return x;

  if (init) {
    if (s[l] != s[r])
      return x = -INF;
    return x = solve(l + 1, r - 1, 1, s, memo) + 1 + (l != r);
  }

  x = max(x, max(solve(l + 1, r, 0, s, memo), solve(l + 1, r, 1, s, memo)));
  x = max(x, max(solve(l, r - 1, 0, s, memo), solve(l, r - 1, 1, s, memo)));
  return x;
}

string printAns(int ans, string &s, dp &memo) {
  string t = s.substr(0, 1);

  for (int l = 0; l < s.length(); l++) {
    for (int r = s.length() - 1; r >= 0; r--) {
      if (memo[l][r][1] == ans && (r - l + 1) == ans) {
        return s.substr(l, ans);
      }
    }
  }

  return t;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T = 1e3 + 5;
  dp memo(T, vector<vector<int>>(T, vector<int>(3, -1)));
  string s;
  cin >> s;
  cerr << s.length() << endl;

  int ans = solve(0, s.length() - 1, 0, s, memo);
  ans = max(ans, solve(0, s.length() - 1, 1, s, memo));
  cout << printAns(ans, s, memo) << endl;
  return 0;
}
