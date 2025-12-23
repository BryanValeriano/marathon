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

ll solve(ll bit, vector<ll> v) {
  if (bit == 0) {
    return 0;
  }
  vector<ll> l;
  vector<ll> r;
  for (ll x : v) {
    if (x & bit)
      r.pb(x);
    else
      l.pb(x);
  }
  if (l.size() == 0)
    return solve((bit >> 1), r);
  if (r.size() == 0)
    return solve((bit >> 1), l);
  return min(solve((bit >> 1), l), solve((bit >> 1), r)) + bit;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<ll> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.pb(x);
  }
  ll bit = (1 << 30);
  cout << solve(bit, v) << endl;
  return 0;
}
