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

const int n = 10;

char g[11][11];

bool can(int x, int y) {
	int k = 1;
	int a = 0;

	while(x+k < n and g[x+k][y] == 'X') k++, a++;
	k = 1;
	while(x-k >= 0 and g[x-k][y] == 'X') k++, a++;
	if(a >= 4) return 1;

	a = 0;
	k = 1;
	while(y+k < n and g[x][y+k] == 'X') k++, a++;
	k = 1;
	while(y-k >= 0 and g[x][y-k] == 'X') k++, a++;
	if(a >= 4) return 1;
	
	a = 0;
	k = 1;
	while(y+k < n and x+k < n and g[x+k][y+k] == 'X') k++, a++;
	k = 1;
	while(y-k >= 0 and x-k >= 0 and g[x-k][y-k] == 'X') k++, a++;
	if(a >= 4) return 1;

	a = 0;
	k = 1;
	while(y+k < n and x-k >= 0 and g[x-k][y+k] == 'X') k++, a++;
	k = 1;
	while(y-k >= 0 and x+k < n and g[x+k][y-k] == 'X') k++, a++;
	if(a >= 4) return 1;

	return 0;
}
 
int main() {
    ios_base::sync_with_stdio(false);

	for(int i = 0; i < n; i++) cin >> g[i];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(g[i][j] == '.' and can(i,j)) { cout << "YES" << endl; return 0; }

	cout << "NO" << endl; 
    
    return 0;
}

