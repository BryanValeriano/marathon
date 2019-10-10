#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int MAXN = 1e5 + 5;
const int MAXM = 9e5 + 5;
int ned, first[MAXN], work[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM], dist[MAXN];

void init() {
	memset(first, -1, sizeof first);
	ned = 0;
}

void add(int u, int v, int f) {
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

int dfs(int u, int f, int s, int t) {
	if(u == t) return f;
	int v, df;
	for(int &e = work[u]; e != -1; e = nxt[e]) {
		v = to[e];
		if(dist[v] == dist[u] + 1 and cap[e] > 0) {
			df = dfs(v, min(f, cap[e]), s, t);
			if(df > 0) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs(int s, int t) {
	int u, v;
	memset(&dist, -1, sizeof dist);
	dist[s] = 0;
	queue<int> q; q.push(s);
	while(!q.empty()) {
		u = q.front(); q.pop();
		for(int e = first[u]; e != -1; e = nxt[e]) {
			v = to[e];
			if(dist[v] < 0 and cap[e] > 0) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return dist[t] >= 0;
}

int dinic(int s, int t) {
	int result = 0, f;
	while(bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while(f = dfs(s, INF, s, t)) result += f;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);

	init();
	int n;
	cin >>n;
	for(int i = 1; i <= n; i++) {
		add(0, i, 1);

		int qtd[30];
		int maior = 0;
		memset(qtd, 0, sizeof qtd);
		vector<int> v;
		for(int j = 0; j < 3; j++) {
			string s;
			cin >>s;
			for(auto c:s) {
				qtd[c-'A']++;
				if(qtd[c-'A'] > maior) {
					maior = qtd[c-'A'];
					v.clear();
				}
				if(qtd[c-'A'] == maior) 
					v.pb(c-'A');
			}
		}
		for(auto at:v) add(i, n+at+1, 1);
	}
	int k; cin >>k;
	for(int j = 'A'; j <= 'Z'; j++) {
		add(n+(j-'A')+1, n+35, k);
	}

	cout <<dinic(0, n+35) <<endl;
	
	return 0;
}
 
