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
    ll goal;
    cin >> goal;
    string prefix = "133";
    string suffix = "7";

    int threes = 0;
    int sevens = goal - 1;

    for (ll i = 3; (i * (i - 1) / 2) <= goal; i++) {
      threes = i - 2;
      sevens = goal - (i * (i - 1) / 2);
    }

    cout << prefix;
    for (int i = 0; i < sevens; i++)
      cout << '7';
    for (int i = 0; i < threes; i++)
      cout << '3';
    cout << suffix << endl;
  }
  return 0;
}
