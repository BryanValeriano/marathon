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
const int T = 1e5+5;
ll fat[T];

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

int main() {
    ios_base::sync_with_stdio(false);
    fat[0] = 1;
    for(ll i = 1; i < T; i++) fat[i] = (i*fat[i-1])%MOD;
    ll n,k; cin >> n >> k;
    cout << (fat[n]*inv(ele(2,k)))%MOD << endl;
    return 0;
}

