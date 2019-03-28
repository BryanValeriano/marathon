#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int T = 1005;
bool v[T][T];
int vis[T][T];
int mapa[T*T];
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
		if(isIn(ii,jj) and v[ii][jj] and !vis[ii][jj])
			ans += dfs(ii,jj);
	}

	return (ans%10);
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	char tmp;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			cin >> tmp;
			if(tmp == '.') v[i][j] = 1;
		}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(v[i][j] and !vis[i][j]) ++t, mapa[t] = dfs(i,j);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(!v[i][j]) {
				vis[i][j] = 1;
				set<int>pegos;
				for(int k = 0; k < 4; k++) {
					int ii = i + mov[k][0];
					int jj = j + mov[k][1];
					if(isIn(ii,jj) and v[ii][jj] and !pegos.count(vis[ii][jj])) {
						vis[i][j] += mapa[vis[ii][jj]] % 10;
						pegos.insert(vis[ii][jj]);
					}
				}
				vis[i][j] %= 10;
			}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(v[i][j]) cout << '.';
			else cout << vis[i][j];
		}
		cout << endl;
	}

    return 0;
}
