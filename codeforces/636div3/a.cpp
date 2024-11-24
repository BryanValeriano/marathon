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

int main() {
  ios_base::sync_with_stdio(false);
  ll T = 1e9;
  ll x = 3;
  vector<ll> v;
  v.pb(x);
  while (x < T) {
    x += (x + 1);
    v.pb(x);
  }
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    for (ll x : v) {
      if (n % x == 0) {
        cout << n / x << endl;
        break;
      }
    }
  }
  return 0;
}
