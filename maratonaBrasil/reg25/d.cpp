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
const int T = 21;
int dp[1 << T][T][2];
vector<ii> leftt[T];
vector<ii> rightt[T];

// left == 0 == fi
// right == 1 == se
int solve(int mask, int at, bool side) {
  if (__builtin_popcount(mask) == 1)
    return 1;
  int &r = dp[mask][at][side];
  if (r != -1)
    return r;

  int ans = 0;
  if (!side) {
    for (auto [fir, sec] : leftt[at]) {
      if (!(mask & (1 << fir))) {
        continue;
      }
      ans |= solve(mask - (1 << at), fir, sec);
    }
  } else {
    for (auto [fir, sec] : rightt[at]) {
      if (!(mask & (1 << fir))) {
        continue;
      }
      ans |= solve(mask - (1 << at), fir, sec);
    }
  }
  return r = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    vector<ii> deck;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      deck.emplace_back(x, y);
    }

    for (int i = 0; i < n; i++) {
      leftt[i].clear();
      rightt[i].clear();
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          continue;
        if (deck[i].fi == deck[j].fi)
          leftt[i].emplace_back(j, 1);
        if (deck[i].se == deck[j].fi)
          rightt[i].emplace_back(j, 1);

        if (deck[i].fi == deck[j].se)
          leftt[i].emplace_back(j, 0);
        if (deck[i].se == deck[j].se)
          rightt[i].emplace_back(j, 0);
      }
    }

    memset(dp, -1, sizeof dp);
    int masks = 1 << n;
    ll ans = 0;

    for (int mask = 1; mask < masks; mask++) {
      bool work = 0;
      for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i)))
          continue;

        work |= solve(mask, i, 0) | solve(mask, i, 1);
      }
      ans += (ll)work;
    }
    cout << ans << endl;
  }

  return 0;
}
