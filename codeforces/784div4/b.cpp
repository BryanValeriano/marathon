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

void cleanFreq(vector<int> &v) {
  for (int x : v) {
    freq[x]--;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    int ans = -1;
    vector<int> v;
    while (n--) {
      int x;
      cin >> x;
      v.pb(x);
      freq[x]++;
      if (freq[x] > 2) {
        ans = x;
      }
    }
    cout << ans << endl;
    cleanFreq(v);
  }
  return 0;
}
