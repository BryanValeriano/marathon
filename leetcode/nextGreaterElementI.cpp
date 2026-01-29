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
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    map<int, int> ans;
    vector<pair<int, int>> sortedNums2;

    for (int i = 0; i < nums2.size(); i++) {
      sortedNums2.emplace_back(nums2[i], i + 1);
    }
    sort(sortedNums2.begin(), sortedNums2.end());

    set<int> indexOfGreaterElements;
    while (sortedNums2.size() != 0) {
      pair<int, int> top = sortedNums2.back();
      sortedNums2.pop_back();
      auto x = indexOfGreaterElements.upper_bound(top.second);
      cout << top.fi << " -> " << *x << endl;
      ans[top.first] =
          (x == indexOfGreaterElements.end() ? -1 : nums2[(*x) - 1]);
      indexOfGreaterElements.insert(top.second);
    }

    vector<int> nums1Ans;
    for (int x : nums1) {
      nums1Ans.push_back(ans[x]);
    }

    return nums1Ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  Solution *solution = new Solution();
  vector<int> nums1 = {4, 1, 2};
  vector<int> nums2 = {1, 3, 4, 2};
  vector<int> ans = solution->nextGreaterElement(nums1, nums2);
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
