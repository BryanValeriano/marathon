#include <bits/stdc++.h>
#include <climits>
#include <cmath>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e5 + 5;
vector<int> graph[T];
vector<ll> sumWeights;

void clear(int n) {
  sumWeights.clear();
  for (int i = 0; i <= n; i++)
    graph[i].clear();
}

void readGraph(int edgeQtd) {
  while (edgeQtd--) {
    int u, v;
    cin >> u >> v;
    graph[u].pb(v);
    graph[v].pb(u);
  }
}

void readWeights(int m) {
  sumWeights.pb(0);
  while (m--) {
    int x;
    cin >> x;
    sumWeights.pb(x);
  }
  sort(sumWeights.begin(), sumWeights.end());
  for (int i = 1; i < sumWeights.size(); i++) {
    sumWeights[i] += sumWeights[i - 1];
  }
}
void bfs(int origin, vector<int> &dist) {
  queue<int> bag;
  bag.push(origin);
  dist[origin] = 0;

  while (!bag.empty()) {
    int at = bag.front();
    bag.pop();
    for (int v : graph[at]) {
      if (dist[v] == INT_MAX) {
        bag.push(v);
        dist[v] = dist[at] + 1;
      }
    }
  }
  return;
}

ll solve(int doubleWeight, int singleWeight1, int singleWeight2) {
  if (doubleWeight + singleWeight1 + singleWeight2 >= sumWeights.size()) {
    return LLONG_MAX;
  }
  ll distB = sumWeights[doubleWeight];
  ll distA = sumWeights[doubleWeight + singleWeight1] - distB;
  ll distC =
      sumWeights[doubleWeight + singleWeight1 + singleWeight2] - distB - distA;
  return distB * 2ll + distA + distC;
}

ll solveForX(int n, vector<int> &doubleWeightDist,
             vector<int> &singleWeight1Dist, vector<int> &singleWeight2Dist) {
  ll ans = LLONG_MAX;
  for (int x = 1; x <= n; x++) {
    ans = min(ans, solve(doubleWeightDist[x], singleWeight1Dist[x],
                         singleWeight2Dist[x]));
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    readWeights(m);
    readGraph(m);
    vector<int> distA(n + 2, INT_MAX);
    vector<int> distB(n + 2, INT_MAX);
    vector<int> distC(n + 2, INT_MAX);
    bfs(a, distA);
    bfs(b, distB);
    bfs(c, distC);
    cout << solveForX(n, distB, distA, distC) << endl;
    clear(n);
  }
  return 0;
}
