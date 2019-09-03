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
 
struct edge {
	int to, cap, flow, rid; 
 
	edge () {}
 
	edge(int a, int b, int c, int d) :
		to(a), cap(b), flow(c), rid(d) {}
};
 
const int N = 210;
string id[N];
vector<edge> g[N];
 
void add(int a, int b, int c) {
	g[a].pb(edge(b,c,0,g[b].size()));
	g[b].pb(edge(a,0,0,g[a].size()-1));
}
 
ii pai[N];
 
int bfs(int s, int t) {
	for(int i = 0; i < N; i++) pai[i] = ii(-1,-1);
	queue<ii> q;
	q.push(ii(s,INF));
 
	while(!q.empty()) {
		int at = q.front().fi;
		int free = q.front().se;
		q.pop();
 
		for(int i = 0; i < g[at].size(); i++) {
			edge edg = g[at][i];
			if(pai[edg.to].fi == -1 and edg.cap - edg.flow > 0) {
				int f = min(edg.cap - edg.flow, free);
				q.push(ii(edg.to, f));
				pai[edg.to] = ii(at, i);
				if(edg.to == t) return f;
			}
		}
	}
 
	return 0;
}
 
int max_flow(int s, int t) {
	int ret = 0;
	while(1) {
		int f = bfs(s,t);
 
		if(!f) break;
 
		for(int at = t; at != s; at = pai[at].fi) {
			edge &edg = g[pai[at].fi][pai[at].se];
			edg.flow += f;
			edge &redg = g[edg.to][edg.rid];
			redg.flow -= f;
		}
 
		ret += f;
	}
 
	return ret;
 
}
 
ii dig(string x) {
	ii ans = mk(0,0);
	for(int i = 0; i < 3; i++) ans.fi += (x[i] - '0');
	for(int i = 3; i < 6; i++) ans.se += (x[i] - '0');
	return ans;
}
 
int vis[N];
 
void find_MinCut(int at, int s) {
	vis[at] = 1;
    if(at >= 102) return;
 
	for(int i = 0; i < g[at].size(); i++) {
		edge edg = g[at][i];
		int next = edg.to;
		if(edg.flow == 1 and next != s and at != s and next >= 102 and next < N-1) {
			ii a = dig(id[at]);
			ii b = dig(id[next]);
			if(a.fi == b.se) cout << "AT " << id[at] << " " << id[next] << endl;
			else cout << "TA " << id[next] << " " << id[at] << endl;
		} 
        else if(!vis[next]) find_MinCut(next, s);
	}
}
 
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
 
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
 
	for(int i = 1; i <= n; i++) {
		cin >> id[i];
		add(0,i,1);
	}
	for(int i = 102; i < 102+m; i++) {
		cin >> id[i]; 
		add(i, N-1, 1);
	}
 
	for(int i = 1; i <= n; i++) {
		for(int j = 102; j < 102+m; j++) {
			ii a = dig(id[i]);
			ii b = dig(id[j]);
			if(a.fi == b.se or a.se == b.fi) add(i,j,1);
		}
	}
	
	cout << max_flow(0, N-1) << endl;
	find_MinCut(0,0);
 
	return 0;
}
 
