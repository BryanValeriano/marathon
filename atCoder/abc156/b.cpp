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
const ll LIM = 1e10;

ll calc(ll b, ll e) {
    ll ans = 1;

    for(ll i = 1; i <= e; i++) {
        if(LIM/b <= ans) return 0;
        ans *= b;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;

    ll until = 0;
    int ans = 0;

    for(ll i = 32; i >= 0; i--) {
        if(!calc(k,i)) continue;

        ll tmp = calc(k,i);
        cout << i << " " << tmp << " | ";
        bool ok = 0;

        for(ll j = 0; j < k; j++) {
            if(until + tmp <= n) until += tmp, ok = 1;
            else break;
            if(LIM/k <= tmp) break;
            tmp *= k;
        }

        cout << until << " " << ans << endl;
        ans += ok;
    }


    cout << ans << endl;
    return 0;
}

