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
const int T = 4e5 + 10;
int v[T];
ll ans[T];

int main() {
  ios_base::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
    }
    for (int i = 1; i <= n / 2; i++) {
      int maior = v[i];
      int menor = v[n - i + 1];
      if (maior < menor) {
        swap(maior, menor);
      }

      int bordaL1 = menor + 1;
      int bordaR1 = maior + k;
      ans[bordaL1] += 1;
      ans[bordaR1 + 1] -= 1;

      if (bordaL1 > 2) {
        ans[2] += 2;
        ans[bordaL1] -= 2;
      }
      if (bordaR1 < 2 * k) {
        ans[bordaR1 + 1] += 2;
        ans[2 * k + 1] -= 2;
      }

      // cout << bordaL1 << " -> " << bordaR1 + 1 << " | ";
      // cout << 2 << " -> " << bordaL1 << " | ";
      // cout << bordaR1 + 1 << " -> " << 2 * k + 1 << endl;
      // cout << "------------------" << endl;
    }
    ll mini = INF;
    for (int i = 2; i <= 2 * k; i++) {
      ans[i] += ans[i - 1];
    }
    for (int i = 1; i <= n / 2; i++) {
      int x = v[i] + v[n - i + 1];
      ans[x] -= 1;
    }
    for (int i = 2; i <= 2 * k; i++) {
      // cout << ans[i] << " ";
      mini = min(mini, ans[i]);
    }
    // cout << endl;
    cout << mini << endl;
    // cout << "@@@@@@@@@@@@@@@@" << endl;
    for (int i = 1; i <= 2 * k + 3; i++) {
      ans[i] = 0;
    }
  }
  return 0;
}
