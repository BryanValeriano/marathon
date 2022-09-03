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
const int T = 2e5+5;
ll v[T], fat[T];
ll n,m,k;

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

ll choose(ll z, ll x) {
    if(x > z) return 0;
    return (fat[z]*inv((fat[z-x]*fat[x]%MOD)))%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    fat[0] = 1;
    for(ll i = 1; i < T; i++) fat[i] = (i*fat[i-1])%MOD;

    while(tc--) {
        cin >> n;
        cin >> m >> k;
        ll ans = 0;

        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v,v+n);
        int l = 0;
        int r = 0;

        while(l < n) {
            while(r+1 < n && v[r+1]-v[l] <= k) r++;
            ans = (ans+choose(r-l,m-1))%MOD;
            l++;
        }

        cout << ans << endl;
    }
    return 0;
}

