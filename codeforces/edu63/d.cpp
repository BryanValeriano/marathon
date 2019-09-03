#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const ll INF = -2e18;

const int T = 3e5 + 10;
ll v[T];
ll best[T];
ll dp[T][4];
int n;
ll x;

ll solve(ll at, int mask) {
	if(at > n) return 0;
	if(dp[at][mask] != -1) return dp[at][mask];

	ll ans = -INF;
	if(mask == 0) {
		ans = solve(at+1, 1) + (best[at-1] + x*v[at]);	
		ans = max(ans,solve(at+1, 0));
	}
	else if(mask == 1) {
		ans = solve(at+1,1) + x*v[at];
		ans = max(ans,solve(at,2));
	} else if(mask == 2) {
		ans = solve(at+1,2) + v[at];
		ans = max(ans,solve(at+1,3));
	} else ans = solve(at+1,mask);
	
	return dp[at][mask] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> x;
	memset(dp, -1, sizeof dp);
	for(int i = 1; i <= n; i++) cin >> v[i];
	
	ll aux = 0;
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		aux += v[i];
		if(aux < 0) aux = 0;
		best[i] = aux;
		ans = max(ans,aux);
	}

	ans = max(ans,solve(1,0));
	cout << ans << endl;

    return 0;
}
