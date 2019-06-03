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

ll MOD = 1e9 + 7;

__int128 ele(__int128 base, __int128 e) {
    __int128 ans = 1;
    while(e) {
        if(e&1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        e >>= 1;
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);

    int tc; cin >> tc;
    while(tc--) {
        ll aa,bb,nn;
        cin >> aa >> bb >> nn;

        __int128 a,b,n;
        a = aa; b = bb; n = nn;

        __int128 fdp = abs(aa-bb);
        if(fdp) MOD = fdp;

        __int128 xx = (ele(a,n) + ele(b,n)) % MOD;
        ll x = xx;
        MOD = 1e9 + 7;

        if(!fdp) cout << x << endl;
        else {
            ll y = __gcd(xx,fdp) % MOD;
            cout << y << endl;
        }

    }

    return 0;
}

