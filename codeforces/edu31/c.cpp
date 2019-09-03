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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
const int T = 1e5 + 3;
int pai[T];
int peso[T];
bool vis[T];
bool corn[T];
int g[T];
int n;
 
void pre() {
	for(int i = 0; i < T; i++) {
		pai[i] = i;
		peso[i] = 1;
	}
}
 
int find(int x) {
	return (x == pai[x]? x : pai[x] = find(pai[x]));
}
 
void join(int x, int y) {
	x = find(x);
	y = find(y);
	if(x == y) return;
 
	if(peso[x] < peso[y]) swap(x,y);
	pai[y] = x;
	peso[x] += peso[y];
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
	pre();
	int x;
	cin >> n;
 
	for(int i = 1; i <= n; i++) {
		cin >> x;
		join(i,x);
		g[i] = x;
	}
 
	ll best = 0; 
	ll best2 = 0;
	int id = 0;
	int id2 = 0;
 
	for(int i = 1; i <= n; i++) {	
		x = find(i);
		if(vis[x]) continue;
		if(peso[x] > best) {
			best2 = best;
			id2 = id;
			best = peso[x];
			id = x;
		}
		else if(peso[x] > best2) best2 = peso[x], id2 = x;
		vis[x] = 1;
	}
		
	ll ans = (best+best2)*(best+best2);
 
	memset(vis,0,sizeof vis);
 
	for(int i = 1; i <= n; i++) {
		x = find(i);
		if(x == id or x == id2) vis[i] = 1;
	}
 
	for(int i = 1; i <= n; i++) {
		x = find(i);
		if(g[i] == i) corn[x] = 1;
	}
 
	for(int i = 1; i <= n; i++) {
		x = find(i);
		if(vis[x]) continue;
		ll y = peso[x];
		if(corn[x]) ans += (y*(y-1))+1;
		else ans += y*y;
		vis[x] = 1;
	}
		
	cout << ans << endl; 
    return 0;
}
