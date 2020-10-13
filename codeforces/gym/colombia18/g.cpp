#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 5e3+2;
const ll MOD = 1e9+7;
int n,m;
ll p[T],q[T],cp[T],v[T];
string s;
ll dp[T][T];

ll ele(ll b, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (b*ans) % MOD;
        b = (b*b) % MOD;
        e >>= 1;
    }
    return ans;
}

ll inv(ll x) { return ele(x,MOD-2); }

ll solve(int at, int pos) {
    if(pos == m) return 1;
    if(m-pos > n-at) return 0;
    if(dp[at][pos] != -1) return dp[at][pos];
    dp[at][pos] = solve(at+1,pos)*((cp[v[pos]]*q[v[pos]])%MOD)%MOD;
    if(pos< m) dp[at][pos] = (dp[at][pos]+(solve(at+1,pos+1)*((p[v[pos]]*q[v[pos]])%MOD)%MOD))%MOD;
    return dp[at][pos];
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n >> m;
    cin >> s;
    for(int i = 0; i < m; i++) v[i] = s[i]-'a';
    for(int i = 0; i < 26; i++) {
        cin >> p[i] >> q[i];
        cp[i] = q[i]-p[i];
        q[i] = inv(q[i]);
    }
    cout << solve(0,0) << endl;
    return 0;
}

