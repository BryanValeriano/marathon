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
const int T = 1e5+10;
ll fat[T];

ll ele(ll base, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = ans*base%MOD;
        base = base*base%MOD;
        e >>= 1;
    }
    return ans;
}

ll inv(ll x) {
    return ele(x,MOD-2);
}

ll choose(ll n, ll k) {
    return fat[n]*inv(fat[k]*fat[n-k]%MOD)%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    fat[0] = 1;
    for(ll i = 1; i < T; i++) fat[i] = i*fat[i-1]%MOD;
    while(tc--) {
        ll n; cin >> n;
        ll maxi = 0;
        ll qtd = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x > maxi) maxi = x, qtd = 1;
            else if(x==maxi) qtd++;
        }
        ll ans = ele(2,n);

        if(qtd&1) {
            cout << ans << endl;
            continue;
        }

        ans = (ans-((choose(qtd,qtd>>1)*ele(2,n-qtd))%MOD)+MOD)%MOD;
        cout << ans << endl;
    }
    return 0;
}

