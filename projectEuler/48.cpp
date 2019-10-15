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

const ll MOD = 1e10;
const int T = 1e3;

ll exp(__int128 base, __int128 e) {
    __int128 ans = 1;
    while(e) {
        if(e&1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        e >>= 1;
    }
    return (ll)ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll ans = 0;
    for(ll i = 1; i <= T; i++) ans = (ans + exp(i,i)) % MOD;
    cout << ans << endl;
    return 0;
}

