#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 110;

int linR, linB, linG;
vector<ii> tR, tB, tG;
char g[T][T];
bool vis[T][T];
int iniR[T];
int iniG[T];
int iniB[T];
int n, m;

int dfs(int i, int j) {
	vis[i][j] = 1;
	int ans = 1;

	if(j+1 < m and !vis[i][j+1] and g[i][j] == g[i][j+1])
		ans += dfs(i,j+1);

	return ans;
}

bool check() {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(g[i][j] != 'R' and g[i][j] != 'B' and g[i][j] != 'G') return 0;
	return 1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> g[i][j];
	
	if(!check()) {
		cout << "NO" << endl;
		return 0;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(g[i][j] == 'G' and !vis[i][j]) {
				tG.eb(i,dfs(i,j));
				iniG[linG] = j;
				linG++;
			} else if(g[i][j] == 'R' and !vis[i][j]) {
				tR.eb(i,dfs(i,j));
				iniR[linR] = j;
				linR++;
			} else if(g[i][j] == 'B' and !vis[i][j]) {
				tB.eb(i,dfs(i,j));
				iniB[linB] = j;
				linB++;
			}
		}
	}

	bool ok = tG.size() and tB.size() and tR.size();

	if(!(linG == linR and linG == linB)) {
		cout << "NO" << endl;
		return 0;
	}

	ok &= (tG[0].se == tB[0].se and tG[0].se == tR[0].se);
	
	for(int i = 1; i < tG.size(); i++) {
		ok &= (tR[i].fi == (tR[i-1].fi + 1) and tR[i].se == tR[i-1].se);
		ok &= (tB[i].fi == (tB[i-1].fi + 1) and tB[i].se == tB[i-1].se);
		ok &= (tG[i].fi == (tG[i-1].fi + 1) and tG[i].se == tG[i-1].se);
		ok &= (iniG[i] == iniG[i-1]);
		ok &= (iniB[i] == iniB[i-1]);
		ok &= (iniR[i] == iniR[i-1]);
		ok &= (tG[i].se == tB[i].se and tG[i].se == tR[i].se);
	}

	if(ok) cout << "YES" << endl;
	else cout << "NO" << endl;
    
    return 0;
}
