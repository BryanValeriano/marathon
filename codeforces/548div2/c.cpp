#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 10;
const ll MOD = 1e9 + 7;
bool vis[T];
vector<int> g[T];

ll exp(ll base, ll e) {
	ll ans = 1;
	while(e) {
		if(e&1) ans = (ans * base) % MOD;
		base = (base * base) % MOD;
		e >>= 1;
	}

	return ans;
}

ll dfs(int u) {
	vis[u] = true;
	ll ans = 1;

	for(auto v : g[u]) 
		if(!vis[v]) ans += dfs(v);

	return ans;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	ll n, k, u, v, tp;
	cin >> n >> k;
	ll ans = (exp(n,k)) % MOD;
	for(int i = 0; i < n-1; i++) {
		cin >> u >> v >> tp;
		if(!tp) {	
			g[u].pb(v);
			g[v].pb(u);
		}
	}

	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			ll qtd = dfs(i);
			ans = (ans - exp(qtd,k)) % MOD;
			ans = (ans + MOD) % MOD;
		}
	}

	cout << ans%MOD << endl;

	return 0;
}

