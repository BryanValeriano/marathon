#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define cc(x) cout << #x << " = " << x << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
 
const int T = 2e5 + 5;
int ori[T][3];
vector<int> g[2][T];
int vis[T];
int n,m,a,b, v;

void bfs(int x, int z, int op) {
	vis[x] = v;
	queue<ii> lista;
	lista.emplace(x,0);

	while(!lista.empty()) {
		ii tmp = lista.front();
		int at = tmp.fi;
		int d = tmp.se;	

		lista.pop();

		ori[at][op] = d;

		for(auto nxt : g[z][at]) {
			if(vis[nxt] != v) {
				vis[nxt] = v;
				lista.emplace(nxt,d+1);
			}
		}
	}
}
		

int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> m >> a >> b;
	memset(ori,INF,sizeof ori);
	int x,y;

	for(int i = 0; i < m; i++) {
		cin >> x >> y;
		g[0][x].pb(y);
		g[1][y].pb(x);
	}
	
	v++; bfs(0,0,0);
	v++; bfs(a,1,1);
	v++; bfs(b,1,2);

	int ans = INT_MAX;
	for(int i = 0; i <= n; i++) {
		//cout << i << " " << ori[i][0] << " " << ori[i][1] << " " << ori[i][2] << endl;
		ans = min(ans, ori[i][0] + ori[i][1] + ori[i][2]);
	}

	cout << ans << endl; 

    return 0;
}

