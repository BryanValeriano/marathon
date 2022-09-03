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

const ll MOD = 1e9+7;
const int T = 102;
ll n,k,d;
ll dp[T][2];

ll solve(int pos, bool hasD) {
	if(dp[pos][hasD] != -1) return dp[pos][hasD];
	if(pos == n and hasD) return 1;
	ll ans = 0;
	for(int j = 1; j <= k; j++) {
		if(pos+j > n) break;
		ans = (ans + solve(pos+j, hasD | (j>=d))) % MOD;
	}
	return dp[pos][hasD] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof dp);
	cin >> n >> k >> d;
	cout << solve(0,0) << endl;
    return 0;
}

