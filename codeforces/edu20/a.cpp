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

const int T = 110;
bool mat[T][T];
int dig = 1;
int n;
int x = 0;
int y = 0;
int k;

bool lados() {
	if(y == n) x++, y = x;
	if(x == n) return false;
	mat[x][y] = 1;
	mat[y][x] = 1;
	if(x == y) k--;
	else k -= 2;
	if(k < 0) return false;

	y++;
	return true;
}

bool nextdig() {
	for(int i = 0; i < n; i++) 
		if(!mat[i][i]) {
			mat[i][i] = 1;
			return true;
		}
	return false;
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> k;

	while(k) {
		if(!lados()){ cout << -1 << endl; return 0; }
		if(k == 1) {
			if(!nextdig()) { cout << -1 << endl; return 0; }
			else break;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
    
    return 0;
}

