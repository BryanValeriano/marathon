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
const int T = 2e5 + 10;
const ll MOD = 998244353;
ll ans[T];
ll m[T];

ll ele(ll base, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (ans*base)%MOD;
        base = (base*base)%MOD;
        e >>= 1;
    }
    return ans;
}

ll mul(ll x, ll y) { return (x*m[y])%MOD; }
ll divi(ll x, ll y) { return (x*ele(m[y],MOD-2))%MOD; }

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    m[1] = 10;
    for(int i = 2; i <= n; i++) m[i] = (m[i-1]*10)%MOD;
    ans[1] = 10;
    ans[2] = 180;
    ans[3] = 2610;
    for(int i = 4; i <= n; i++) {
        ans[i] = divi(ans[i-1],i-3);
        ans[i] = (ans[i]+81)%MOD;
        ans[i] = mul(ans[i],i-2);
    }
    for(int i = n; i >= 1; i--) cout << ans[i] << " ";
    cout << endl;
    return 0;
}

