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

const int T = 1e6 + 2;
const ll MOD = 1e9 + 7;

ll f[T];
ll sqr1[T];
ll sqr2[T];

ll expo(ll base, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        e >>= 1;
    }
    return ans;
}

ll fat(ll x) {
    if(~f[x]) return f[x];
    return f[x] = (x * fat(x-1)) % MOD;
}

ll choose(ll x, ll y) {
    return (fat(x+y)*expo(fat(x)*fat(y)%MOD, MOD-2))%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(f,-1,sizeof f);
    f[0] = f[1] = 1;
    f[2]  = 2;
    int h,w,a,b; cin >> h >> w >> a >> b;

    ll ans = 0;

    for(int i = b+1; i <= w; i++) {
        ll up = choose(h-a-1,i-1);
        ll down = choose(a-1,w-i);
        ans = (ans+(up*down)%MOD)%MOD;
    }
    cout << ans << endl;
    return 0;
}

