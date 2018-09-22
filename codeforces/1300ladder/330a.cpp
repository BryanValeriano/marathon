#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
int n, m;
char mat[11][11];
int ans = 0;

bool da(int a, int b, int flag) {
	if(flag == 2) { 
		for(int i = a; i < n; i++) 
			if(mat[i][b] == 'S') return false;
		for(int i = a; i < n; i++) { 
			if(mat[i][b] == 'T') ans--;
			mat[i][b] = 'T';
		}
	} else {
		for(int j = b; j < m; j++)
			if(mat[a][j] == 'S') return false;
		for(int j = b; j < m; j++) {
			if(mat[a][j] == 'T') ans--;
			mat[a][j] = 'T';
		}
	}
	return true;
}

int main() {
    ios::sync_with_stdio(false);
	cin >> n >> m;
	vector< pair<int,int> >row;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	for(int i = 0; i < n; i++)
		if(da(i, 0, 1)) ans += m;
	for(int j = 0; j < m; j++)
		if(da(0, j, 2)) ans += n;

	cout << ans << endl;
    return 0;
}

