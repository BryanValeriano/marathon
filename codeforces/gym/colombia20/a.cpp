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
const double EPS = 1e-6;
const double PI = acos(-1.0);

struct point {
    double x, y;
    point(double x = 0, double y = 0) : x(x), y(y) {}
    point operator+(point p) {
        return point(x + p.x, y + p.y);
    }
    point operator-(point p) {
        return point(x - p.x, y - p.y);
    }
    point operator*(double a) {
        return point(a * x, a * y);
    }
};

double dist(point p, point q) {
    point del = p - q;
    return sqrt(del.x * del.x + del.y * del.y);
}

double norm(point p) {
    return dist(point(), p);
}

point a, b, c, d, u, v, i, j;
double nu, nv;
double f(double x) {
    point p = x < nu ? a + (i * x) : b;
    point q = x < nv ? c + (j * x) : d;
    return dist(p, q);
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;
    u = b - a, v = d - c;
    nu = norm(u), nv = norm(v);
    i = point(u.x / nu, u.y / nu), j = point(v.x / nv, v.y / nv);

    double l = 0, r = min(nu, nv);
    while (r - l > EPS) {
        double del = (r - l) / 3;
        double x = l + del, y = r - del;
        double f1 = f(x), f2 = f(y);
        if (f1 <= f2) r = y;
        if (f1 >= f2) l = x;
    }
    double ans = f(l);
    l = min(nu, nv), r = max(nu, nv);
    while (r - l > EPS) {
        double del = (r - l) / 3;
        double x = l + del, y = r - del;
        double f1 = f(x), f2 = f(y);
        if (f1 <= f2) r = y;
        if (f1 >= f2) l = x;
    }
    ans = min(ans, f(l));
    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}

