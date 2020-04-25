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

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int ok = n;
    ll ans; cin >> ans;
    n--;
    while(n--) {
        ll x; cin >> x;
        ans = x - ans;
    }
    int q; cin >> q;
    while(q--) {
        int l,r; cin >> l >> r;
        ll v; cin >> v;
        if(!((r-l)&1)) ans += ((l&1) == (ok&1)? v : -v);
        cout << ans << endl;
    }
    return 0;
}

