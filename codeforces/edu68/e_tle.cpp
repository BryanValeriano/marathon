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

struct Line {
  int x1, y1, x2, y2;
  Line(int x1_val, int y1_val, int x2_val, int y2_val)
      : x1(x1_val), y1(y1_val), x2(x2_val), y2(y2_val) {}
};

bool intercept(Line v, Line h) {
  if (!(h.x1 <= v.x1 && v.x1 <= h.x2))
    return false;
  if (!(v.y1 <= h.y1 && h.y1 <= v.y2))
    return false;
  return true;
}

void buildQuickV(vector<int> &hasHorizontal, vector<vector<int>> &equals) {
  for (int i = 0; i < hasHorizontal.size(); i++) {
    for (int j = i + 1; j < hasHorizontal.size(); j++) {
      int ii = hasHorizontal[i];
      int jj = hasHorizontal[j];
      equals[ii][jj]++;
    }
  }
}

void buildEquals(vector<Line> &vertical, vector<Line> &horizontal,
                 vector<vector<int>> &equals) {
  int vsize = vertical.size();
  equals = vector<vector<int>>(vsize, vector<int>(vsize, 0));

  for (int j = 0; j < horizontal.size(); j++) {
    vector<int> hasHorizontal;
    for (int i = 0; i < vertical.size(); i++) {
      if (intercept(vertical[i], horizontal[j])) {
        hasHorizontal.pb(i);
      }
    }
    buildQuickV(hasHorizontal, equals);
  }
}

ll countCombs(int i, int j, vector<vector<int>> &equals) {
  ll equal = equals[i][j];
  return max(0ll, equal * (equal - 1) / 2);
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<Line> vertical;
  vector<Line> horizontal;
  vector<vector<int>> equals;

  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      if (y1 > y2)
        swap(y1, y2);
      vertical.emplace_back(x1, y1, x2, y2);
    } else {
      if (x1 > x2)
        swap(x1, x2);
      horizontal.emplace_back(x1, y1, x2, y2);
    }
  }

  buildEquals(vertical, horizontal, equals);

  ll ans = 0;

  for (int i = 0; i < vertical.size(); i++) {
    for (int j = i + 1; j < vertical.size(); j++) {
      ans += countCombs(i, j, equals);
    }
  }

  cout << ans << endl;
  return 0;
}
