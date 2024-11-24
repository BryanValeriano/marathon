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
    if (n <= 4) {
      cout << -1 << endl;
      continue;
    }
    deque<int> resp = {1, 3, 5, 4, 2};
    for (int i = 6; i <= n; i++) {
      if (i & 1) {
        resp.push_front(i);
      } else {
        resp.push_back(i);
      }
    }
    for (int x : resp) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}
