#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5;
bool vis[T];
vector<int> gX[T];
vector<int> gY[T];
vector<ii> v;

void dfs(int u) {
	if(vis[u]) return;
	vis[u] = 1;
	for(int e : gX[v[u].fi]) dfs(e);
	for(int e : gY[v[u].se]) dfs(e);
	return;
}

int main() {
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		int x,y; cin >> x >> y;
		v.eb(x,y);
		gX[x].pb(i);
		gY[y].pb(i);
	}

	int grupos = 0;

	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			dfs(i);
			grupos++;
		}
	}

	cout << max(0, grupos-1) << endl;
    return 0;
}

