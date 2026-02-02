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
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> prefix(n, 0);
    vector<int> sufix(n, 0);
    vector<int> ans(n, 0);

    prefix[0] = nums[0];
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] * nums[i];
    }
    sufix[n - 1] = nums[nums.size() - 1];
    for (int i = n - 2; i > 0; i--) {
      sufix[i] = sufix[i + 1] * nums[i];
    }
    for (int i = 0; i < n; i++) {
      int left = (i == 0 ? 1 : prefix[i - 1]);
      int right = (i == n - 1 ? 1 : sufix[i + 1]);
      ans[i] = left * right;
    }

    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  Solution *solution;
  vector<int> v({1, 2, 3, 4});
  vector<int> ans = solution->productExceptSelf(v);
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;

  v = {-1, 1, 0, -3, 3};
  ans = solution->productExceptSelf(v);
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
