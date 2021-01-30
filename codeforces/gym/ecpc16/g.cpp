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
const int T = 1e3+2;
ll fat[T];

ll ele(ll b, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = ans*b%MOD;
        b = b*b%MOD;
        e >>= 1;
    }
    return ans;
}

ll choose(ll n, ll k) {
    ll ans = fat[n];
    ll b = ele((fat[n-k]*fat[k])%MOD,MOD-2);
    return ans*b%MOD;
}

int main() {
    freopen("galactic.in","r",stdin);
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    fat[0] = 1;
    for(ll i = 1; i < T; i++) fat[i] = (i*fat[i-1])%MOD;
    while(tc--) {
        ll n,k;
        cin >> n >> k;
        if(k > n) {
            cout << 0 << endl;
            continue;
        }

        ll ans = ele(k,n);
        ll d = 0;
        ll last = 0;
        for(ll i = 1; i < k; i++) {
            d = (ele(i,n)*choose(k,i))%MOD;
            d = (d-last+MOD)%MOD;
            last = d;
        }
        ans = (ans-d+MOD)%MOD;
        cout << ans << endl;
    }
    return 0;
}

