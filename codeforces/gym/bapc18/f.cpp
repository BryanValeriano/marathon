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
const int T = 1e5 + 2;

ll n,k;
ll v[2][T];

ll check(ll dias) {
    ll tot = 0;
    for(int i = 0; i < n; i++) {
        tot += max(0ll, dias*v[0][i] - v[1][i]);
        if (tot >= 1e9) return tot;
    }
    return tot;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> v[0][i] >> v[1][i];

    ll l = 0;
    ll r = 2e9 + 10;
    ll ans = 0;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        if(check(mid) >= k) ans = mid, r = mid-1;
        else l = mid+1;
    }

    cout << ans << endl; 
    
    return 0;
}

