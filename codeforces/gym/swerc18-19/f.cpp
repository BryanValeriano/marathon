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
const double EPS = 1e-7;

struct point {
    ll x, y;
    point(ll x = 0, ll y = 0) : x(x), y(y) {}
    bool operator==(point& p) {
        return x == p.x and y == p.y;
    }
    bool operator!=(point& p) {
        return x != p.x or y != p.y;
    }
    point operator-(point p) {
        return point(x - p.x, y - p.y);
    }
};

double norm(point p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

double ang(point p) {
  if (p.y == 0 and p.x < 0) return PI; 
  double n = norm(p);
  double ang = acos((double)p.x / n);
  if (sin(ang) * p.y / n < 0) ang = -ang;
  return ang;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    ll tot = 0;
    ll x, y, g;
    vector<pair<point, ll>> ps;
    for (int i = 0;i < n;i++) {
        cin >> x >> y >> g;
        ps.eb(point(x, y), g);
        tot += g;
    }
    ll ans = LLONG_MAX;
    for (int k = 0;k < n;k++) {
        auto& [p, val] = ps[k];
        cerr << "pivo = " << p.x << " " << p.y << endl;
        sort(ps.begin(), ps.end(), [p](pair<point, ll> a, pair<point, ll> b) {
            return ang(a.first - p) < ang(b.first - p);
        });
        ll sum = val;
        ll line = val;
        for (int i = 0, j = 1;i < n;i++) {
            if (ps[i].first == p) continue;
            line += ps[i].second;
            double angi = ang(ps[i].first);
            for (;;j++) {
                double angj = ang(ps[j % n].second);
                if (j >= n) angj += 2 * PI;
                if (angj - angi + EPS > PI) break;
                sum += ps[j % n].second;
            }
            ans = min(ans, abs(tot - sum + line));
            sum -= ps[i].second;
            line -= ps[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}

