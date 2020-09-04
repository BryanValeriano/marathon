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
const int MOD = 1e9+7;
const int N = 1e6+5;
ll fat[N];

ll ele(ll base, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (ans*base)%MOD;
        base = (base*base)%MOD;
        e >>= 1;
    }
    return ans;
}

ll inv(ll x) {
    return ele(x,MOD-2);
}

ll comb(ll a, ll b) {
    return fat[a]*inv(fat[b]*fat[a-b]%MOD)%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    fat[0] = 1;
    for(ll i = 1; i < N; i++) fat[i] = (i*fat[i-1])%MOD;


    int n,m;
    cin >> n >> m;
    ll last = 0;
    ll ans = 0;

    for(int k = 1; k <= n; k++) {
        ll small = (comb(m+k-1,m)-last+MOD)%MOD;
        ll big = comb(n-k+m,m);
        ans = (ans + (small*big)%MOD)%MOD;
        last = (small+last)%MOD;
    }

    cout << ans << endl;
    return 0;
}

