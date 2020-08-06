#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,ll> ii;
typedef tuple<ll,ll,ll> tl;
typedef vector<tl> vtl;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
vtl v1, v2;

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int x,y; cin >> x >> y;
        v1.eb(x-y,x,y);
        v2.eb(x+y,x,y);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    ll ans = 0;
    ll ans2 = 0;
    ll cost1 = 0;
    ll cost2 = m+1;

    for(int i = 0; i < n; i++) {
        ll x,y;
        tie(ignore,x,y) = v1[i];
        if(x-y > cost1+1) {
            ll anda = x-y-cost1-1;
            cost1 = x+y+anda;
            ans += anda;
        } else cost1 = max(cost1,x+y);
    }
    if(cost1 < m) ans += m-cost1;

    for(int i = n-1; i >= 0; i--) {
        ll x,y;
        tie(ignore,x,y) = v1[i];
        if(x+y < cost2-1) {
            ll anda = cost2-(x+y)-1;
            cost2 = x-y-anda;
            ans2 += anda;
        } else cost2 = min(cost2,x-y);
    }
    if(cost2 > 1) ans2 += cost2-1;

    cout << min(ans,ans2) << endl;

    return 0;
}

