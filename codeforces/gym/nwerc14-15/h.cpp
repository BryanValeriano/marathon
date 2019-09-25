#include "bits/stdc++.h"
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
 
#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)
 
#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
 
#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 
 
typedef long long int ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<ll,ll> pll;
 
const int INF = 0x3f3f3f3f;
const int T = 1e4 + 4;
vector<int> g[T];
bool vis[T];
int x[T];
int y[T];
int cnt;

void dfs(int at) {
	vis[at] = 1;
	int cont = 0;
	for(int v : g[at]) {
		if(!vis[v]) {
			cont++;
			if(g[v].size() > 1) {
				x[v] = (cont&1? y[at] : x[at]);
				y[v] = ++cnt;
			} else {
				x[v] = x[at];
				y[v] = y[at];
			}
			dfs(v);
		}
	}
}
 
int main(){
	fastio;
	int n; cin >> n;
	for(int i = 0; i < n-1; i++) { 
		int a,b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}

	x[1] = 1;
	y[1] = 2;
	cnt = 2;
	dfs(1);
	for(int i = 1; i <= n; i++)
		cout << x[i] << " " << y[i] << endl;
}