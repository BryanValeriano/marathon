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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1005;
char v[T][T];
char ans[T][T];
int vis[T][T];
int mapa[T];
int t = 0;
int n,m;

int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

bool isIn(int i, int j) {
	return (i >= 0 and i < n and j >= 0 and j < m);
}

int dfs(int i, int j) {
	vis[i][j] = t;
	int ans = 1;

	for(int k = 0;  k < 4; k++) {
		int ii = i + mov[k][0];
		int jj = j + mov[k][1];
		if(isIn(ii,jj) and v[ii][jj] == '.' and vis[ii][jj] != t)
			ans += dfs(ii,jj);
	}

	return (ans%10);
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) 
			cin >> v[i][j], ans[i][j] = '.';

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(v[i][j] == '.') ++t, mapa[t] = dfs(i,j);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(v[i][j] == '*') {
				set<int> pegos;
				bool flag = false;
				ans[i][j] = 1;
				for(int k = 0; k < 4; k++) {
					int ii = i + mov[k][0];
					int jj = j + mov[k][1];
					if(isIn(ii,jj) and v[ii][jj] == '.' and !pegos.count(vis[ii][jj])) {
						ans[i][j] += mapa[vis[ii][jj]] % 10;
						pegos.insert(vis[ii][jj]);
						flag = true;
					}
				}
				if(!flag) ans[i][j] = '0';
				else ans[i][j] %= 10, ans[i][j] += '0';
			}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			cout << ans[i][j];
		cout << endl;
	}
    return 0;
} 
