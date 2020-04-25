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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2;
const int N = 200;
ll dp[T][N];

ll a,b,n,p;

ii operator * (const ii &a, const ii &b) {
    ii ans;
    ans.fi = a.fi*b.fi;
    ans.se = a.se*b.se;
    ll gcd = __gcd(ans.fi,ans.se);
    ans.fi /= gcd;
    ans.se /= gcd;
    return ans;
}

ii operator - (const ii &a, const ii &b) {
    ll mmc = (a.se*b.se)/__gcd(a.se,b.se);
    ll x = a.fi*(mmc/a.se);
    ll y = b.fi*(mmc/b.se);
    ll z = x-y;
    ll gcd = __gcd(z,mmc);
    return mk(z/gcd,mmc/gcd);
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> a >> b >> n >> p;
        ll gcd = __gcd(a,b);
        ii ok = mk(a/gcd,b/gcd);
        ii tmp = mk(1,10);
        ii tmp2 = mk(10,1);
        while(ok.fi/ok.se > 0) ok = (ok*tmp);
        ll ans = 0;

        for(int j = 0; j < p; j++) dp[0][j] = 0;
        bool atual = 1, ultimo = 0;

        for(int i = 0; i < n; i++) {
            ok = (ok*tmp2);
            ll at = ok.fi/ok.se;
            ll sobra = at%p;
            for(int j = 0; j < p; j++) dp[atual][j] = 0;
            dp[atual][sobra] = 1;
            for(int j = 0; j < p; j++)
                dp[atual][(j*10+sobra)%p] += dp[ultimo][j];
            ans += dp[atual][0];
            ok = ok - mk(at,1);
            ultimo = !ultimo, atual = !atual;
        }

        cout << ans << endl;

    }
    return 0;
}

