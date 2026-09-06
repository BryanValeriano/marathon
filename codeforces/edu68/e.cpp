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

#define LSOne(S) ((S) & -(S))

const int MAX_CORD = 5001;
const int T = MAX_CORD * 2 + 5;
int BIT[T];

enum SweepType {
  // we are going to use this enum order
  // for the sort order
  Horizontal,   // 0
  Vertical_ini, // 1
  Vertical_end, // 2
};

struct SweepObj {
  int x1;
  int x2;
  int y;
  int id;
  SweepType type;

  SweepObj(int x1, int x2, int y, int id, SweepType type)
      : x1(x1), x2(x2), y(y), id(id), type(type) {}

  bool operator<(const SweepObj &b) const {
    return tie(y, type, x1, x2, id) < tie(b.y, b.type, b.x1, b.x2, b.id);
  }
};

vector<SweepObj> readLinesInfo(int n) {
  vector<SweepObj> linesInfo;

  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // all values >= 0
    x1 += MAX_CORD;
    x2 += MAX_CORD;
    y1 += MAX_CORD;
    y2 += MAX_CORD;

    if (y1 > y2)
      swap(y1, y2);
    if (x1 > x2)
      swap(x1, x2);

    if (x1 != x2) {
      // horizontal line
      linesInfo.emplace_back(x1, x2, y1, i, Horizontal);
    } else {
      // vertical line
      linesInfo.emplace_back(x1, x2, y1, i, Vertical_ini);
      linesInfo.emplace_back(x1, x2, y2, i, Vertical_end);
    }
  }

  sort(linesInfo.begin(), linesInfo.end());
  return linesInfo;
}

void update(int k, int val) {
  for (; k < T; k += LSOne(k)) {
    BIT[k] += val;
  }
}
int query(int b) {
  int sum = 0;
  for (; b > 0; b -= LSOne(b)) {
    sum += BIT[b];
  }
  return sum;
}

int query(int a, int b) { return query(b) - query(a - 1); }

ll solveSweep(vector<SweepObj> &linesInfo) {
  ll possibleRectangles = 0;
  int n = linesInfo.size();

  for (int i = 0; i < n; i++) {
    SweepObj fixed = linesInfo[i];
    if (fixed.type != Horizontal)
      continue;
    unordered_set<int> usedLines;

    for (int j = 0; j < n; j++) {
      SweepObj current = linesInfo[j];
      if (i == j)
        continue;
      switch (current.type) {
      case Vertical_ini:
        if (current.y > fixed.y || current.x1 < fixed.x1 ||
            current.x1 > fixed.x2)
          continue;
        update(current.x1, 1);
        usedLines.insert(current.id);
        break;
      case Vertical_end:
        if (!usedLines.count(current.id))
          continue;
        update(current.x1, -1);
        usedLines.erase(current.id);
        break;
      case Horizontal:
        if (current.y <= fixed.y)
          continue;
        int x11 = max(fixed.x1, current.x1);
        int x22 = min(fixed.x2, current.x2);
        ll x = query(x11, x22);
        possibleRectangles += x * (x - 1) / 2;
        break;
      }
    }
  }

  return possibleRectangles;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<SweepObj> linesInfo = readLinesInfo(n);
  ll possibleRectangles = solveSweep(linesInfo);
  cout << possibleRectangles << endl;
  return 0;
}
