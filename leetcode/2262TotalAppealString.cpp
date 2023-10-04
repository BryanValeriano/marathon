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

class Solution {
public:
  long long appealSum(string s) {
    vector<vector<int>> lookup(30, vector<int>(1, 0));
    for (int i = 0; i < s.length(); i++) {
      lookup[s[i] - 'a'].pb(i);
    }
    for (int i = 0; i < 30; i++) {
      lookup[i].pb(s.length() - 1);
    }
    ll ans = 0;
    for (int i = 0; i < lookup.size(); i++) {
      for (int j = 1; j < lookup[i].size() - 1; j++) {
        ll l = max(0, lookup[i][j] - lookup[i][j - 1] - 1);
        ll r = max(0, lookup[i][j + 1] - lookup[i][j] - 1);
        ans += (l * r + l + r + 1);
        cout << (char)('a' + i) << " = " << l << " | " << r << " -> "
             << (l * r + l + r + 1) << endl;
      }
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  string s;
  cin >> s;
  Solution *solution = new Solution();
  cout << solution->appealSum(s) << endl;
  return 0;
}
