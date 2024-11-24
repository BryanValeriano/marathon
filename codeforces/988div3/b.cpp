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
const int T = 2e5 + 5;
int freq[T];

int main() {
  ios_base::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int k;
    cin >> k;
    int n, m;
    vector<int> v;
    int K = k - 2;
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      v.pb(x);
      if (K % x == 0) {
        if (freq[K / x]) {
          n = K / x;
          m = x;
        }
      }
      freq[x]++;
    }
    for (int x : v) {
      freq[x] = 0;
    }
    cout << n << " " << m << endl;
  }
  return 0;
}
