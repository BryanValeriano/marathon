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
ll n,a,b;

ll ele(ll b, ll e) {
    ll ans = 1;

    while(e) {
        if(e&1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }

    return ans % MOD;
}

ll f(ll n, ll x) {
    ll a = 1;
    ll b = 1;
    for(ll i = n-x+1; i <= n; i++) a = (a * i) % MOD;
    for(ll i = 1; i <= x; i++) b = (b * i) % MOD;
    return (a * ele(b,MOD-2))%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    ll ans = ele(2,n);
    ans = (ans - f(n,a) + MOD) % MOD;
    ans = (ans - f(n,b) + MOD) % MOD;
    cout << (ans-1+MOD)%MOD << endl;
    return 0;
}

