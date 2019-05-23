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

const int T = 1e3 + 10;
set<int> s[T];
vector<int> g[T];
int in[T];
int tin[T];
int tout[T];
vector<ii> ans;
int n,t;

void dfs(int u) {
    tin[u] = ++t;

    for(auto v : g[u])
        dfs(v);

    tout[u] = t;
}
        

bool check() {
    if(ans.size()) dfs(ans.begin()->fi);

    for(int i = 1; i <= n; i++) { 
        if(tout[i] - tin[i] != s[i].size()) return false;
        for(auto z : s[i]) 
            if(!(tin[i] < tin[z] and tout[i] >= tout[z])) return false; 
    }

    return true;
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> n;

	for(int i = 1; i <= n; i++) {
		int m; cin >> m;
		for(int j = 0; j < m; j++) {
			int x; cin >> x;
			if(x == i) {
				cout <<"NO" <<endl;
				return 0;
			}
			in[x]++;
			s[i].insert(x);
		}
		if(s[i].size() != m) { cout << "NO" << endl; return 0; }
	}

	queue<int> fila;
	for(int i = 1; i <= n; i++) if(!in[i]) fila.push(i);
	if(fila.size() > 1) { cout << "NO" << endl; return 0; }

	while(!fila.empty()) {
		int at = fila.front();
		fila.pop();
		for(auto v : s[at]) {
			in[v]--;
			if(!in[v]) ans.eb(at,v), g[at].pb(v), fila.push(v);
		}
	}
	
	if(ans.size() == n-1 and check()) {
		cout << "YES" << endl;
		for(auto z : ans) cout << z.fi << ' ' << z.se << endl;
	} else {
		cout << "NO" << endl;
	}
    
    return 0;
}

