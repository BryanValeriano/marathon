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

struct dsu {
  vector<int> id, sz;

  dsu(int n) : id(n), sz(n, 1) {
    for (int i = 0;i < n;i++) id[i] = i;
  }

  int find(int x) {
    return x == id[x] ? x : id[x] = find(id[x]);
  }

  bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (sz[a] > sz[b]) swap(a, b);
    id[a] = id[b];
    sz[b] += sz[a];
    return true;
  }
};

struct point {
    ll x, y;
    point(ll x = 0, ll y = 0) : x(x), y(y) {}
    point operator-(point p) {
        return point(x - p.x, y - p.y);
    }
};

struct line {
    ll a, b, c;
    line(point p, point q) {
        point del = p - q;
        a = -del.y;
        b = del.x;
        c = -(a * p.x + b * p.y);
        ll m = gcd(abs(a), gcd(abs(b), abs(c)));
        if (a < 0) m = -m;
        a /= m, b /= m, c /= m;
    }
    ll operator()(point p) {
        return a * p.x + b * p.y + c;
    }
};

istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y;
    return is;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<line> ls;
    for (int i = 0;i < n;i++) {
        point a, b;
        cin >> a >> b;
        ls.emplace_back(a, b);
    }
    vector<point> ps;
    dsu uf(m);
    for (int i = 0;i < m;i++) {
        point p;
        cin >> p;
        for (int j = 0;j < i;j++) {
            int cnt = 0;
            for (line& l : ls) {
                if ((l(p) < 0) xor (l(ps[j]) < 0)) {
                    cnt++;
                    if (cnt > 1) break;
                }
            }
            if (cnt <= 1) uf.join(i, j);
        }
        ps.push_back(p);
    }
    int ans = 0;
    for (int i = 0;i < m;i++) ans = max(ans, uf.sz[uf.find(i)]);
    cout << ans << endl;
    return 0;
}