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
typedef pair<ll,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e6 + 3;
const ll MOD = 1e9+7;
ll v[T];

ll ele(ll base, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (ans * base) % MOD;
        base = (base*base)%MOD;
        e >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 0; i < n; i++) cin >> v[i];

    ll ans = 0;
    ll qtd = 0;

    for(int i = 0; i < n; i++) {
        if(v[i]&1 and !qtd) ans = (ans+ele(2,i))%MOD;
        qtd += v[i];
        qtd /= 2;
    }

    cout << ans << endl;
    return 0;
}

