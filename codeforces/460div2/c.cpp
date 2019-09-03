#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int tam = 2e3 + 3;
char mat[tam][tam];
int lin[tam][tam];
int col[tam][tam];

int main() {
    ios::sync_with_stdio(false);
	int n, m, k; cin >> n >> m >> k;
	int resp = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> mat[i][j];
			lin[i][j] += lin[i-1][j] + (mat[i][j] == '*');
			col[i][j] += col[i][j-1] + (mat[i][j] == '*');
			if(i >= k) resp += (lin[i][j] == lin[i-k][j]);
			if(k > 1 && j >= k) resp += (col[i][j] == col[i][j-k]);
		}
	}
	cout << resp << endl;
    return 0;
}

