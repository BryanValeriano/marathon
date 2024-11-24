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
const int T = 22;
int v[T];

int main() {
  ios_base::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    int resp = 0;
    while (n--) {
      int x;
      cin >> x;
      v[x]++;
      if (!(v[x] & 1)) {
        resp++;
      }
    }
    cout << resp << endl;
    memset(v, 0, sizeof(v));
  }
  return 0;
}
