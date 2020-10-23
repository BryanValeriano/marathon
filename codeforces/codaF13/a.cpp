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
const int T = 3e5+5;
ll v[T];

ll ele(ll b, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (ans*b) % MOD;
        b = (b*b)%MOD;
        e >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];
    sort(v+1,v+n+1);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = (ans - ((v[i]*ele(2,n-i))%MOD) + MOD) % MOD;
        ans = (ans + ((v[i]*ele(2,i-1))%MOD)) % MOD;
    }
    cout << ans << endl;
    return 0;
}

