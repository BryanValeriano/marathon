#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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

ll dp[T][2];
int n,k,d;

int solve(int at, bool ok) {
    if(at == n) return ok;
    if(~dp[at][ok]) return dp[at][ok];

    dp[at][ok] = 0;
    for(int i = 1; i <= k; i++) {
        if(i+at > n) break;
        dp[at][ok] = (dp[at][ok] + solve(at+i, ok|(i>=d))) % MOD;
    }

    return dp[at][ok];
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n >> k >> d;
    cout << solve(0,0) << endl;
    return 0;
}

