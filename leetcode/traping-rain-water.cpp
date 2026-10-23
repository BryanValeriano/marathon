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
  int trap(vector<int> &height) {
    int n = height.size();

    vector<int> maxLeft(n + 5, 0);
    vector<int> maxRight(n + 5, 0);
    for (int i = 1; i <= n; i++) {
      maxLeft[i] = max(maxLeft[i - 1], height[i - 1]);
    }
    for (int i = n; i >= 1; i--) {
      maxRight[i] = max(maxRight[i + 1], height[i - 1]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += max(0, min(maxRight[i], maxLeft[i]) - height[i - 1]);
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  Solution *sol;
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << sol->trap(height) << endl;
  return 0;
}
