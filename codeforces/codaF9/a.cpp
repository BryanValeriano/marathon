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
    ll b,q,l,m;
    cin >> b >> q >> l >> m;
    set<ll> bag;

    while(m--) {
        ll x; cin >> x;
        bag.insert(x);
    }

    ll ans = 0;
    ll ok = 0;
    while(abs(b) <= l) {
        ok++;
        if(!bag.count(b)) ans++;
        b = b*q;
        if(ok > 100) break;
    }

    if(ans < 40) cout << ans << endl;
    else cout << "inf" << endl;
    return 0;
}

