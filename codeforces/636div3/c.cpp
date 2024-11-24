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
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    ll last;
    ll sum = 0;
    ll bigger = 0;
    cin >> last;
    bigger = last;
    n -= 1;
    while (n--) {
      ll x;
      cin >> x;
      if (last * x < 0) {
        sum += bigger;
        bigger = -INF;
      }
      last = x;
      bigger = max(bigger, last);
    }
    sum += bigger;
    cout << sum << endl;
  }
  return 0;
}
