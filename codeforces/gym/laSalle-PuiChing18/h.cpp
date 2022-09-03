#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
int n;
vii v;

int bef(ll x, ll y) {
    int l = 0, r = v.size()-1, ans = 0;
    while(l <= r) {
        int mid = (l+r)>>1;
        if(y - v[mid].fi <= x) r = mid-1, ans = mid;
        else l = mid+1;
    }

    return ans;
}

int solve(ll x, ll y) {
    int s = bef(x,y);
    int a = max(0, s-1), b = s;
    int aa = (y - v[a].fi <= 0? INF: abs(y - v[a].fi - x));
    int bb = (y - v[b].fi <= 0? INF: abs(y - v[b].fi - x));
    int cc = abs(y-x);
    return (cc <= aa && cc <= bb? 0 : aa <= bb && aa <= cc? v[a].se : v[b].se);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        ll x; cin >> x;
        v.eb(x,i);
    }
    v.eb(1e12, n+1);
    int q; cin >> q;
    while(q--) {
        ll x,y; cin >> x >> y;
        cout << solve(x,y) << endl;
    }
    return 0;
}
