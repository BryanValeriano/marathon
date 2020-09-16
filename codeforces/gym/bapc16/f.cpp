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

int idx = 0;

struct point {
    double x, y;
    point(ll x = 0, ll y = 0) : x(x), y(y) {}
    point operator-(point p) {
        return point(x - p.x, y - p.y);
    }
    bool operator<(const point p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
    point operator*(ll a) {
        return point(x * a, y * a);
    }
};

double cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

struct street {
    int id;
    string name;
    ll a, b, c;
    point dir;
    vector<pair<point, int>> inter;
    street(string s, point p, point q) : id(idx++), name(s) {
        if (q < p) swap(p, q);
        point dir = q - p;
        a = -dir.y;
        b = dir.x;
        c = -(a * p.x + b * p.y);
        ll m = gcd(abs(a), gcd(abs(b), abs(c)));
        if (m) {
            if (a < 0) m = -m;
            a /= m;
            b /= m;
            c /= m;
        }
    }
    bool inside(point p) {
        return !(a * p.x + b * p.y + c);
    }
};

pair<point, bool> intersection(street& a, street& b) {
    if (a.a == b.a and a.b == b.b and a.c == b.c) return {point(), false};
    double x = (double)(a.b * b.c - b.b * a.c) / a.a * b.b + a.b * b.a;
    double y = a.b == 0 ? -(x * a.a - a.c) / a.b : -(x * b.a - b.c) / b.b;
    return {point(x, y), true};
}

int main() {
    ios_base::sync_with_stdio(false);

    ll r, n;
    point h;
    cin >> r >> n >> h.x >> h.y;
    vector<street> ss;
    for (int i = 0;i < r;i++) {
        string s;
        ll a, b, c, d;
        cin >> s >> a >> b >> c >> d;
        ss.emplace_back(s, point(a, b), point(c, d));
        for (int j = 0;j < i;j++) {
            auto [p, ok] = intersection(ss[i], ss[j]);
            if (ok) {
                ss[i].inter.emplace_back(p, j);
                ss[j].inter.emplace_back(p, i);
            }
        }
    }
    int at;
    for (auto& st : ss) {
        sort(st.inter.begin(), st.inter.end());
        if (st.inside(h)) at = st.id;
    }
    vector<int> visit(r, -1);
    point dir = ss[at].dir, cur = h;
    for (int i = 0;i < n;i++) {
        visit[at] = i;
        cerr << ss[at].name << " = " << i << endl;
        int pos = upper_bound(ss[at].inter.begin(), ss[at].inter.end(), make_pair(cur, INF)) - ss[at].inter.begin() - 1;
        int nxt = pos + (cross(dir, ss[at].dir) < 0 ? -1 : 1);
        if (nxt < 0 or nxt > ss[at].inter.size()) {
            cerr << nxt << " " << ss[at].inter.size() << endl;
            cerr << "infinity" << endl;
            break;
        }
        tie(cur, at) = ss[at].inter[nxt];
        cerr << "turn to " << ss[at].name << " in " << cur.x << " " << cur.y << endl;
        if (visit[at] != -1) {
            cerr << ss[at].name << " already visited" << endl;
            int l = i - visit[at] + 1;
            n %= l;
            break;
        }
    }
    for (int i = 0;i < r;i++) {
        if (visit[i] == n) {
            at = i;
            break;
        }
    }
    cout << ss[at].name << endl;
    return 0;
}

