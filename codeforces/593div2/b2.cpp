#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const ll MOD = 1e9 + 7;
ll n,m;

ll ele(ll base, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        e >>= 1;
    }
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    if(m == 1) { cout << 1 << endl; return 0;; }
    ll ans = ele(2,m)-1;
    ans += MOD;
    ans %= MOD;
    ans = ele(ans,n);
    cout << ans << endl;
    return 0;
}

