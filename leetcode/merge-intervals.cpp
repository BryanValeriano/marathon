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
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) {
           if (a[0] < b[0]) {
             return true;
           }
           if (a[0] > b[0]) {
             return false;
           }
           // else the first element is equal
           return (a[1] < b[1]);
         });

    int start = intervals[0][0];
    int end = intervals[0][1];
    vector<vector<int>> ans;
    for (vector<int> interval : intervals) {
      if (end < interval[0]) {
        ans.push_back({start, end});
        start = interval[0];
        end = max(end, interval[1]);
      } else {
        end = max(end, interval[1]);
      }
    }
    ans.push_back({start, end});
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  Solution *solution;
  vector<vector<int>> ans = solution->merge(intervals);
  for (vector<int> interval : ans) {
    cout << interval[0] << " | " << interval[1] << endl;
  }
  return 0;
}
