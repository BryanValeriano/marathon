#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const ll INF = 1e18;

int n, need;
ll k;
vii v;

bool check(ll x) {
    ll a = 0;
    int wow = 0;
    vector<ll> tmp;

    for(int i = 0; i < n; i++) {
        if(v[i].fi >= x) wow++;
        else if(v[i].se >= x) tmp.pb(x-v[i].fi);
    }
    
    sort(tmp.begin(), tmp.end());
    if((need-wow) > (int)tmp.size()) return 0;
    for(int i = 0; i < need-wow; i++)  a += tmp[i]; 

    return (a <= k);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> k;
        v.clear();

        for(int i = 0; i < n; i++) {
            ll x,y; cin >> x >> y;
            v.eb(x,y);
            k -= x;
        }

        need = (n/2)+1;
        ll ans = 0;
        ll l = 0;
        ll r = 1e9;

        while(l <= r) {
            ll mid = (l+r) >> 1;
            if(check(mid)) ans = max(ans,mid), l = mid+1;
            else r = mid-1;
        }

        cout << ans << endl;

    }

    
    
    return 0;
}

