#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 55;
int n,m;

char g[T][T];
char f[T][T];

bool square(int x, int y) {
	if(x == n or y == m) return false;
	return (g[x][y] == g[x+1][y] and g[x][y] == g[x][y+1] and g[x][y] == g[x+1][y+1]
		and g[x][y] == '1');
}

void make(int x, int y) {
	f[x][y] = f[x+1][y] = f[x][y+1] = f[x+1][y+1] = '1';
}

vii ans;

int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> g[i][j], f[i][j] = '0';

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(square(i,j)) ans.eb(i,j), make(i,j);

	bool ok = 1;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ok &= g[i][j] == f[i][j];

   	if(!ok) { cout << -1 << endl; return 0; }

	cout << ans.size() << endl;

	for(auto k : ans) cout << k.fi << " " << k.se << endl;
    return 0;
}
