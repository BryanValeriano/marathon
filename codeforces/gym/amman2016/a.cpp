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

const int T = 310;
const int N = 3e4 + 1e3;
const int MOD = 1e9 + 7;

ll dp[T][N];
int v[T];
ll n,m,k,w;

ll solve(int at, int sum) {
	if(at == n and abs(sum - (w-sum)) > k) return 0;
	if(at == n+m) return (sum == w? 1 : 0); 
	if(dp[at][sum] != -1) return dp[at][sum];

	ll ans = ( solve(at + 1, sum + v[at]) + solve(at + 1, sum) ) % MOD;

	return dp[at][sum] = ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	while(tc--) {
		memset(dp, -1, sizeof dp); 
		cin >> n >> m >> k >> w;
		for(int i = 0; i < n; i++) cin >> v[i];
		for(int i = n; i < n+m; i++) cin >> v[i];
		cout << solve(0,0) << endl;
	} 
    return 0;
}

