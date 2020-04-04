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
const ll MOD = 1e9 + 7;
const int T = 1e3 + 2;
ll f[T];

ll ele(ll base, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (ans*base)%MOD;
        base = (base*base)%MOD;
        e >>= 1;
    }
    return ans;
}

ll fat(ll x) {
    if(~f[x]) return f[x];
    return f[x] = (x * fat(x-1))%MOD;
}

ll choose(ll n, ll k) {
    ll base = (fat(k)*fat(n-k))%MOD;
    return (fat(n)*ele(base,MOD-2))%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    memset(f,-1,sizeof f);
    f[0] = f[1] = 1;

    while(tc--) {
        ll a,b,c;
        cin >> a >> b >> c;
        ll ans = 0;
        ll chooseC = (ele(2,c)-1+MOD)%MOD;

        for(ll i = 2; i <= a; i++) {
            ll chooseA = choose(a,i);
            ll maxB = min(b,i-1);
            ll chooseB = 0;

            for(int j = 1; j <= maxB; j++)
                chooseB = (chooseB+choose(b,j))%MOD;

            chooseB = (chooseB*chooseC)%MOD;
            chooseB = (chooseB*chooseA)%MOD;
            ans = (ans+chooseB)%MOD;
        }

        cout << ans << endl;
    }
    return 0;
}

