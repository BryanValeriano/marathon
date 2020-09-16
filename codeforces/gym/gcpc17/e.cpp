#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,double> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e3;
double eps = 1e-7;
vii g[T];
double dist[T];

void bellman(int n) {
	for(int i = 0; i < n; i++)
		for(int u = 0; u <= n; u++)
			for(ii v : g[u])
                dist[v.fi] = min(dist[v.fi],dist[u]+v.se);
}

bool cycle(int n) {
	for(int i = 0; i < n; i++)
		for(int u = 0; u <= n; u++)
			for(ii v : g[u])
                if(eps < dist[v.fi] - (dist[u]+v.se))
                    return 1;
    return 0;
}


int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  int a, b;
  double c;

  for (int i = 0;i < m;i++) {
    cin >> a >> b >> c;
    g[a].eb(b, -log(c));
  }

  for(int i = 1; i <= n; i++) {
    g[0].eb(i,0);
    dist[i] = INF;
  }

  bellman(n);
  bool ok = cycle(n);
  cout << (ok ? "inadmissible" : "admissible") << endl;
  return 0;
}

