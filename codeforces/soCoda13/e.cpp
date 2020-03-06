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
const int T = 5e3 + 3;
const ll MOD = 1e9+7;
ll dp[2][T];
ll l[T];
ll r[T];

ll calc(int j, bool ok) {
    return (dp[ok][r[j]] - dp[ok][l[j]-1] - (dp[ok][j] - dp[ok][j-1] + MOD) + MOD + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(l,INF,sizeof l);
    ll n,a,b,k;
    cin >> n >> a >> b >> k;

    for(int i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            if(abs(i-j) < abs(i-b)) {
                l[i] = min(l[i],j);
                r[i] = max(r[i],j);
            }
        }
    }

    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) dp[0][i] += dp[0][i-1]+(i != b);

    bool ok = 0;

    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            if(j == b) continue;
            dp[!ok][j] = calc(j, ok);
        }
        for(int i = 1; i <= n; i++) dp[!ok][i] = (dp[!ok][i] + dp[!ok][i-1]) % MOD;
        ok = !ok;
    }

    cout << (dp[ok][a] - dp[ok][a-1] + MOD) % MOD << endl;

    return 0;
}

