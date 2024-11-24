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

void solve(int n) {
  ll sum = 0;
  cout << "YES" << endl;
  for (int i = 1; i <= n / 2; i++) {
    ll x = 2 * ll(i);
    cout << x << " ";
    sum += x;
  }
  for (int i = 1; i <= (n / 2) - 1; i++) {
    ll x = 2 * ll(i) - 1;
    cout << x << " ";
    sum -= x;
  }
  cout << sum << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    if ((n / 2) % 2) {
      cout << "NO" << endl;
      continue;
    }
    solve(n);
  }
  return 0;
}
