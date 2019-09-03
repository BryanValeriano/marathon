#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)   cout << #x << " = " << x << endl
#define ok      cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int fudeu = 3e5;

int n, a;

char mat[18][21][21];
int dp[18][fudeu];
int limpa[18][fudeu];
int c[18][fudeu];
int d[18][18];
int qtd[18];
int gol;

int dist(int x, int y) {
	int ans = 0;
	for(int i = 0; i < 21; i++)
		for(int j = 0; j < 21; j++)
			if(mat[x][i][j] != mat[y][i][j]) ans++;
	return ans;
}

int solve(int at, int mask) {
	if(mask == gol) return 0;
	if(dp[at][mask] != -1) return dp[at][mask];
	
	int ans = INF;
	
	for(int i = 0; i < n; i++) {
		if(! (mask & (1<<i))) { 
			int x = solve(i, mask | (1<<i)) + min(qtd[i] + a, d[at][i]);
			if(x < ans) {
				c[at][mask] = i, ans = x;
				(qtd[i] + a < d[at][i])? limpa[at][mask] = 1 : limpa[at][mask] = 0;
			}
		}
	}
	
	return dp[at][mask] = ans;
}

void constroi(int x, int y) {
	cout << x+1 << endl;
	if(limpa[x][y]) cout << "*" << endl;
	if(c[x][y] == -1) return;
	constroi(c[x][y], y | (1 << c[x][y]));
}

int main() {
	cin >> n >> a;
	
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < 21; j++)
			for(int k = 0; k < 21; k++) {
				cin >> mat[i][j][k];
				if(mat[i][j][k] == '1') qtd[i]++;
			}
	
	memset(c, -1, sizeof c);
    memset(dp, -1, sizeof dp);
				
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++) {
			int x = dist(i,j);
			d[i][j] = x;
			d[j][i] = x;
		}
	
	gol = pow(2,n) - 1;
	
	int start;
	int ans = INF;
	
	for(int i = 0; i < n; i++) {
		int x = solve(i, (1<<i)) + qtd[i];
		if(x < ans) ans = x, start = i; 
	}
			
	cout << ans << endl;
	constroi(start, (1<<start));
	
	return 0;
}
