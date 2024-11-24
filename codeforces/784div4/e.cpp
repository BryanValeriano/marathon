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

bool diffByOne(string a, string b) {
  bool ans = (a[0] != b[0]) && (a[1] == b[1]);
  ans |= (a[0] == b[0]) && (a[1] != b[1]);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    map<string, int> freq;
    while (n--) {
      string s;
      cin >> s;
      freq[s]++;
    }
    map<string, int>::iterator i;
    ll ans = 0;
    for (i = freq.begin(); i != freq.end(); i++) {
      map<string, int>::iterator j = i;
      j++;
      for (; j != freq.end(); j++) {
        if (diffByOne(i->first, j->first)) {
          ans += ll(i->second) * ll(j->second);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
