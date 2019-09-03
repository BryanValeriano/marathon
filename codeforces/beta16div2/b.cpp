#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector< ii > vii;
const int INF = 0x3f3f3f3f;

vii v;

int main() {
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    int x,y;

    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        v.eb(y,x);
    }

    sort(v.begin(), v.end(), [] (const ii &a, const ii &b) { return a.fi > b.fi; });

    ll ans = 0;
    ll pegos = 0;
    int i = 0;

    while(i < m and pegos < n) {
        ll tmp = min(v[i].se, n - pegos);
        ans += tmp*v[i].fi;
        pegos += tmp;
        i++;
    }

    cout << ans << endl;

    return 0;
}

