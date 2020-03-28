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
typedef tuple<ll,ll,ll> ti;
typedef vector<ti> vti;
typedef vector<ii> vii;
const ll INF = 1e14;
const double PI = acos(-1.0);
const int T = 1e3 + 2;
vti v;

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        ll x,y,z; cin >> x >> y >> z;
        v.eb(x,y,z);
    }

    ll ans = 0;

    for(int i = 0; i < 8; i++) {
        sort(v.begin(), v.end(), [&] (const ti &a, const ti &b) {
                ll ax,ay,az;
                ll bx,by,bz;
                tie(ax,ay,az) = a;
                tie(bx,by,bz) = b;
                if(i&1) ax = -ax, bx = -bx;
                if(i&2) ay = -ay, by = -by;
                if(i&4) az = -az, bz = -bz;
                return (ax+ay+az > bx+by+bz);

        });
        ll x = 0, y = 0, z = 0;
        for(int j = 0; j < m; j++) {
            x += get<0>(v[j]);
            y += get<1>(v[j]);
            z += get<2>(v[j]);
        }
        ans = max(ans, abs(x) + abs(y) + abs(z));
    }

    cout << ans << endl;

    return 0;
}

