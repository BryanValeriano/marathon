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
const double EPS = 1e-6;

struct point {
    double x, y;
    point(double x, double y) : x(x), y(y) {}
};

int main() {
    ios_base::sync_with_stdio(false);

    double H, W;
    cin >> H >> W;
    vector<point> ps;
    double a, b;
    double top = 0, bot = H, left = W, rig = 0;
    for (int i = 0;i < 4;i++) {
        cin >> a >> b;
        ps.emplace_back(a, b);
        left = min(a, left);
        bot = min(b, bot);
        rig = max(a, rig);
        top = max(b, top);
    }
    double h = top - bot, w = rig - left;
    double x, y;
    if (abs(ps[0].y - ps[1].y) < EPS) {
        if (ps[0].x < ps[1].x) {
            x = (W * left) / (W - w);
        }
        else {
            cerr << W << "*(" << w << "-" << left << ")/" << W << "+" << w << endl;
            x = (W * (w + left)) / (W + w);
        }
    }
    else if (abs(ps[0].x - ps[1].x)) {
        if (ps[0].y < ps[1].y) {
            x = (left + rig * h / H) / (1 - h * w / H * W);
        }
        else {
            x = (left + (rig + w) * h / H) / (1 + h * w / H * W);
        }
    }
    if (abs(ps[1].x - ps[2].x)) {
        if (ps[1].y < ps[2].y) {
            y = (H * bot) / (H - h);
        }
        else {
            y = (H * (h + bot)) / (H + h);
        }
    }
    else if (abs(ps[1].y - ps[2].y)) {
        if (ps[1].x < ps[2].x) {
            y = (bot + top * w / W) / (1 - h * w / H * W);
        }
        else {
            y = (bot + (top + w) * w / W) / (1 + h * w / H * W);
        }
    }
    cout << fixed << setprecision(6) << x << " " << fixed << setprecision(6) << y << endl;
    return 0;
}

