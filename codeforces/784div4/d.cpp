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
    string s;
    cin >> s;
    char need = 'x';
    string ans = "yes";
    for (char c : s) {
      if (c == 'W') {
        if (need == 'B' or need == 'R') {
          ans = "no";
        }
        need = 'x';
      } else if (need == 'x') {
        need = (c == 'R' ? 'B' : 'R');
      } else if (need == c) {
        need = 'o';
      }
    }
    if (need == 'B' or need == 'R') {
      ans = "no";
    }
    cout << ans << endl;
  }
  return 0;
}
