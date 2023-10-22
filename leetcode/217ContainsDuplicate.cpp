#include <algorithm>
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
  bool containsDuplicate(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        return true;
      }
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  Solution *solution = new Solution();
  vector<int> v;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.pb(x);
  }
  cout << solution->containsDuplicate(v) << endl;
  return 0;
}
