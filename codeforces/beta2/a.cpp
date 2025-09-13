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

int getOrder(string name, vector<string> &order) {
  for (int i = 0; i < order.size(); i++) {
    if (name == order[i]) {
      return i;
    }
  }
  return INF;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  map<string, int> points;
  map<int, vector<string>> order;
  while (n--) {
    string name;
    int point;
    cin >> name >> point;
    points[name] += point;
    order[points[name]].pb(name);
  }

  return 0;
}
