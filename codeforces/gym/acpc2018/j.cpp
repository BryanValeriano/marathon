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
    int x, y, z;
    point(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
    point operator-(point p) {
        return point(x - p.x, y - p.y, z - p.z);
    }
};

istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y >> p.z;
    return is;
}

double norm(point p) {
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

double dist(point a, point b) {
    return norm(a - b);
}

point mult(vector<vector<double>>& rot, point p) {
    return point(rot[0][0] * p.x + rot[0][1] * p.y + rot[0][2] * p.z,
                 rot[1][0] * p.x + rot[1][1] * p.y + rot[1][2] * p.z,
                 rot[2][0] * p.x + rot[2][1] * p.y + rot[2][2] * p.z);
}

double dot(point a, point b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("jupiter.in", "r", stdin);

    int t;
    cin >> t;
    for (int i = 0;i < t;i++) {
        point n, a1;
        int l, h;
        cin >> n >> a1 >> l >> h;
        double nnorm = norm(n);
        double sal = n.x / nnorm, cal = sqrt(1 - sal * sal);
        double sbe = - n.y / (nnorm * cal), cbe = sqrt(1 - sbe * sbe);
        vector<vector<double>> r = {
            {cal, 0, sal},
            {sal * sbe, cbe, -cal * sbe},
            {-cbe * sal, sbe, cal * cbe}
        };

        double d = l / sqrt(3);
        point a(-d, 0, 0), b(d / 2, l / 2, 0), c(d / 2, -l / 2, 0);
        a = mult(r, a);
        b = mult(r, b);
        c = mult(r, c);

        double cga = dot(a, a1) / (norm(a) * norm(a1));
        double sga = 1 - cga * cga;
        vector<vector<double>> rot2 = {
            {cga, -sga, 0},
            {sga, cga, 0},
            {0, 0, 1}
        };
        a = mult(rot2, a);
        b = mult(rot2, b);
        c = mult(rot2, c);

        point base(0, 0, -h);
        cout << fixed << setprecision(6) << dist(base, a) << " ";
        cout << fixed << setprecision(6) << dist(base, b) << " ";
        cout << fixed << setprecision(6) << dist(base, c) << endl;
    }
    return 0;
}

