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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct point {
    ll x, y, z;
    point(ll x, ll y, ll z) : x(x), y(y), z(z) {}
};

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<point> ps;
    for (int i = 0;i < n;i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        ps.emplace_back(x, y, z);
    }
    ll a = -INF, b = -INF, c = -INF, d = -INF;
    for (int i = 0;i < n;i++) {
        a = max(a, ps[i].z - ps[i].x);
        b = max(b, ps[i].z + ps[i].x);
        c = max(c, ps[i].z - ps[i].y);
        d = max(d, ps[i].z + ps[i].y);
    }
    ll x = (b - a + 1) / 2, y = (d - c + 1) / 2;
    ll h = max({a + y, b - y, c + x, d - x});
    cout << x << " " << y << " " << h << endl;
    return 0;
}

