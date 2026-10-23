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
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() == 0 or nums2.size() == 0) {
      if (nums1.size() > nums2.size())
        swap(nums1, nums2);
      int middle = nums2.size() / 2;
      int a = nums2[middle];
      int b = (nums2.size() % 2) ? a : nums2[middle + 1];
      return double(a + b) / 2;
    }

    int x1, x2, posX1, posX2;
    int n1 = nums1.size();
    int n2 = nums2.size();
    int middle = (n1 + n2) / 2;

    posX1 = n1 / 2;
    x1 = nums1[posX1];
    posX2 = n2 / 2;
    x2 = nums2[posX2];

    // x2 is always bigger
    // there is (posx1 + posx2) elements smaller
    if (x1 > x2) {
      swap(nums1, nums2);
      swap(x1, x2);
      swap(posX1, posX2);
    }

    for (int i = 0; i < 15; i++) {
      cout << "1 = " << posX1 << " | " << x1 << endl;
      cout << "2 = " << posX2 << " | " << x2 << endl;
      cout << "amount less: " << posX1 + posX2 + 1 << " | value: " << x2
           << endl;
      if (posX1 + posX2 + 1 > middle) {
        // need to reduce x2
        posX2 /= 2;
        x2 = nums2[posX2];
      } else {
        // need to increse x2
        posX1 += posX1 / 2;
        posX1 = min((int)nums1.size() - 1, posX1);
        x1 = nums1[posX1];
      }
      if (x1 > x2) {
        swap(nums1, nums2);
        swap(x1, x2);
        swap(posX1, posX2);
      }
    }

    if ((n1 + n2) % 2 == 0) {
      // there is no element smaller on x2;
      if (posX2 == 0)
        return (double)(x1 + x2) / 2;
      return double(max(x1, nums2[posX2 - 1]) + x2) / 2;
    }

    return x2;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  Solution *sol;
  vector<int> nums1 = {-10, -9, -8};
  vector<int> nums2 = {1, 2};
  double x = sol->findMedianSortedArrays(nums1, nums2);
  cout << x << endl;
  return 0;
}
