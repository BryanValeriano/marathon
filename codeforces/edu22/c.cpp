#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2e5 + 5;

int a[T][2];
int vis[T];
vector<int> g[T];
int ve;

int n,x;

void dist(int at, int op, int d) {
	vis[at] = ve;
	a[at][op] = d;
	
	for(auto v : g[at]) 
		if(vis[v] != ve) dist(v, op, d+1);
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> x;
	int u,v;

	for(int i = 0; i < n-1; i++) {
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	ve++;
	dist(1,0,0);
	ve++;
	dist(x,1,0);

	int ans = 0; 
	int equal = 1e8;

	for(int i = 1; i <= n; i++) {
		if(a[i][0] > a[i][1]) ans = max(ans, a[i][0]);
		if(a[i][0] == a[i][1]) equal = min(equal,a[i][0]);
	}
	if(equal != 1e8) ans = max(ans,equal);
	cout << ans*2 << endl;
    return 0;
}
