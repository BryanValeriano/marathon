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

const int T = 110;
int mat[110][5];
vector<int> ans;
 
int main() {
    ios_base::sync_with_stdio(false);
	int n, m; cin >> n >> m; 
	int impar = 1;
	int par = 2;
	for(int i = 0; i < n; i++) {
		mat[i][0] = impar;
		impar += 2;
	}
	for(int i = 0; i < n; i++) {
		mat[i][1] = impar;
		impar += 2;
	}
	for(int i = 0; i < n; i++) {
		mat[i][3] = par;
		par += 2;
	}
	for(int i = 0; i < n; i++) {
		mat[i][2] = par;
		par += 2;
	}
	for(int i = 0; i < n; i++) {
		ans.pb(mat[i][1]);
		ans.pb(mat[i][0]);
		ans.pb(mat[i][2]);
		ans.pb(mat[i][3]);
	}
	for(auto x : ans) if(x <= m) cout << x << " ";
	cout << endl;
    return 0;
}
