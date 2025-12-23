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

  int n;
  cin >> n;
  ll a = 0;
  for (int i = n; i >= 0; i--) {
    int x;
    cin >> x;
    if (x)
      a |= 1 << i;
  }
  int ans = 0;
  while (a > 1) {
    if (a & 1) {
      a ^= a << 1;
      a ^= 1;
    } else
      a >>= 1;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
