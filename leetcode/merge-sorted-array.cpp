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
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int l = 0;
    int r = 0;
    vector<int> nums3;

    for (int i = 0; i < nums1.size(); i++) {
      int ll = l >= nums2.size() ? INF : nums2[l];
      int rr = r >= nums3.size() ? INF : nums3[r];
      int xx = i >= m ? INF : nums1[i];
      int smallest = min({ll, rr, xx});
      if (smallest == ll) {
        nums3.push_back(xx);
        l++;
      } else if (smallest == rr) {
        nums3.push_back(xx);
        r++;
      }
      nums1[i] = smallest;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  int m = 3;
  vector<int> nums2 = {2, 5, 6};
  int n = 3;
  Solution *solution;
  solution->merge(nums1, m, nums2, n);
  for (auto x : nums1) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
