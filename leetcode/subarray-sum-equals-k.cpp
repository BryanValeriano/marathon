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
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> previousSums;
    int sum = 0;
    int ans = 0;
    previousSums[0] = 1;
    for (int num : nums) {
      sum += num;
      ans += previousSums[sum - k];
      previousSums[sum]++;
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  Solution *sol = new Solution();
  vector<int> nums{1, 1, 1};
  cout << sol->subarraySum(nums, 2) << endl;

  return 0;
}
