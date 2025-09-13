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
    int n;
    string v;
    cin >> n;
    cin >> v;

    ll ans = 0;
    int sum = n;
    vector<ll> balance = vector<ll>(n * 10, 0);
    balance[sum] = 1;

    for (int i = 0; i < v.size(); i++) {
      int value = v[i] - '1';
      sum += value;
      ans += balance[sum];
      balance[sum]++;
    }

    cout << ans << endl;
  }
  return 0;
}
