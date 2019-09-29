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

ll safeDiv(ll x, ll y) {
    if(!y) return 0;
    return x/y;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll ww, sw,ss; cin >> ww >> sw >> ss;
    ll w,s; cin >> w >> s;

    ll k = safeDiv(s,ss);
    ll ans = 0;

    for(ll i = 0; i <= w; i++) {
        if(ww*i > w) break;
        ll a = w - ww*i;
        ll j = min(safeDiv(a,sw),k);
        ans = max(ans,i+j);
    }

    cout << ans << endl;
    return 0;
}

