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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 45;
pair<ll, ll> queryCopyFrom[T];
pair<ll, ll> queryRealInterval[T];
string s;

bool indexInsideInterval(ll index, ll left, ll right) {
  return (index >= left && index <= right);
}

ll getFromInterval(ll index, ll pos) {
  ll start = queryCopyFrom[pos].fi;
  ll distanceFromStart = index - queryRealInterval[pos].fi;
  return start + distanceFromStart;
}

char query(ll index, int c) {
  for (int i = c; i >= 1; i--) {
    if (indexInsideInterval(index, queryRealInterval[i].fi,
                            queryRealInterval[i].se)) {
      index = getFromInterval(index, i);
    }
  }
  return s[index];
}

int main() {
  ios_base::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, c, q;
    cin >> n >> c >> q;
    cin >> s;

    queryCopyFrom[0] = mk(0, n - 1);
    queryRealInterval[0] = mk(0, n - 1);
    for (int i = 1; i <= c; i++) {
      ll l, r;
      cin >> l >> r;
      l--;
      r--;

      queryCopyFrom[i] = mk(l, r);
      queryRealInterval[i] = mk(queryRealInterval[i - 1].se + 1,
                                queryRealInterval[i - 1].se + (r - l + 1));
    }

    while (q--) {
      ll k;
      cin >> k;
      k--;
      cout << query(k, c) << endl;
    }
  }
  return 0;
}
