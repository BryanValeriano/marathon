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
  long long simplifiedEuclidianDist(vector<int> &point) {
    assert(point.size() == 2);
    long long x = point[0];
    long long y = point[1];
    return x * x + y * y;
  }
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    sort(points.begin(), points.end(),
         [&](vector<int> &pointA, vector<int> &pointB) {
           long long distA = simplifiedEuclidianDist(pointA);
           long long distB = simplifiedEuclidianDist(pointB);
           return distA < distB;
         });
    vector<vector<int>> ans(points.begin(), points.begin() + k);
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  Solution *solution = new Solution();
  vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
  vector<vector<int>> ans = solution->kClosest(points, 2);
  for (auto point : ans) {
    cout << point[0] << ", " << point[1] << endl;
  }

  points = {{-2, 2}, {1, 3}};
  ans = solution->kClosest(points, 1);
  for (auto point : ans) {
    cout << point[0] << ", " << point[1] << endl;
  }
  return 0;
}
