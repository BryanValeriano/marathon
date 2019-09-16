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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<ll> va;
vector<ll> vb;

int main() {
    ios_base::sync_with_stdio(false);
    ll n,m,a,b,k;
    ll x;
    cin >> n >> m >> a >> b >> k;

    for(int i = 0; i < n; i++) cin >> x, va.pb(x);
    for(int i = 0; i < m; i++) cin >> x, vb.pb(x);

    if(k >= n or k >= m) {
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;

    for(int i = 0; i <= k; i++) {
        ll start = va[i] + a;
        ll prox = lower_bound(vb.begin(), vb.end(), start) - vb.begin();
        prox += k-i;
        if(prox >= m) {
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, vb[prox]+b);
    }

    cout << ans << endl;

    return 0;
}

