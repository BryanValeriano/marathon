#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
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

    int n, m, L;
    cin >> n >> m >> L;
    vii hurdles;
    for (int i = 0; i < n; i++) {
      int l, r;
      cin >> l >> r;
      hurdles.emplace_back(l, r);
    }

    vii storePowerUp;
    for (int i = 0; i < m; i++) {
      int x, v;
      cin >> x >> v;
      storePowerUp.emplace_back(x, v);
    }

    priority_queue<int> availablePowerUps;
    int posPowerUp = 0;
    ll power = 1;
    int need = 0;

    for (int i = 0; i < n && need != -1; i++) {
      while (posPowerUp < storePowerUp.size() &&
             storePowerUp[posPowerUp].first < hurdles[i].first) {
        int x = storePowerUp[posPowerUp].second;
        availablePowerUps.push(x);
        posPowerUp++;
      }
      int length = hurdles[i].second - hurdles[i].first + 1;
      while (power <= length && !availablePowerUps.empty()) {
        int x = availablePowerUps.top();
        availablePowerUps.pop();
        power += x;
        need++;
      }
      if (power <= length) {
        need = -1;
      }
    }

    cout << need << endl;
  }
  return 0;
}
