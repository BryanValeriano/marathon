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
  vector<int> twoSum(vector<int> &nums, int target) {}
};

int main() {
  ios_base::sync_with_stdio(false);
  Solution *solution = new Solution();
  int n, target;
  vector<int> v;
  cin >> n >> target;
  while (n--) {
    int x;
    cin >> x;
    v.pb(x);
  }
  vector<int> ans = solution->twoSum(v, target);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}
