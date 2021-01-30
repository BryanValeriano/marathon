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
const int T = 3e3+2;
const ll MOD = 998244353;

ll dp[T][T];
int v[T];
int n,s;

ll solve(int at, int k) {
    if(k == s) return (n-at+1);
    if(k > s or at == n) return 0;
    ll &r = dp[at][k];
    if(r!=-1) return r;
    return r = (solve(at+1,k) + solve(at+1,k+v[at])) % MOD;
}

int main() {
    memset(dp,-1,sizeof dp);
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> v[i];

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans = (ans+solve(i,0))%MOD;
    }
    cout << ans << endl;
    return 0;
}

