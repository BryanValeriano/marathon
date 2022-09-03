#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 502;
int dp[T][T][2];
int v[T];
int n;

//ok == 1 -> x is last
//ok == 0 -> v[pos-1] is last
int solve(int pos, int x, bool ok) {
	int last = (ok? x : v[pos-1]);
	x = (ok? v[pos-1] : x);

	if(dp[pos][x][ok] != -1) return dp[pos][x][ok];
	if(pos > n) return 0;


	int l = INF, r = INF;
	if(v[pos] >= last) l = solve(pos+1,x,0);
	if(x >= last && x < v[pos]) r = solve(pos+1,x,1) + 1;

	return dp[pos][x][ok] = min(l,r);
}

int main() {
    ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		memset(dp, -1, sizeof dp);
		int x; cin >> n >> x;
		for(int i = 1; i <= n; i++) cin >> v[i];
		int ans = solve(1,x,0);
		cout << (ans >= INF? -1 : ans) << endl;
	}
    return 0;
}

