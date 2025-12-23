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

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ll l = 0, r = 2000000001;
  auto test = [&](int mid) {
    int p = n - 1;
    for (; p >= 0 and a[p] >= mid; p--)
      ;
    vector<int> b = a;
    for (int i = p, j = 0; i >= 0 and j < k; i--, j++) {
      b[i] += k - j;
    }
    int m = INF;
    for (auto &x : b)
      m = min(m, x);
    return m >= mid;
  };
  while (l < r) {
    ll mid = (l + r) >> 1;
    if (test(mid))
      l = mid + 1;
    else
      r = mid;
  }
  cout << l - 1 << endl;
  return 0;
}
