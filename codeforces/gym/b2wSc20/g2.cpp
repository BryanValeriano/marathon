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
const double eps = 1e-7;
const int T = 5e5+5;
const int N = 5e4+5;
const int R = 1e3;

ll x[T], y[T];
int tri[N][6];
int n,m;
default_random_engine generator;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());


ll sign (int p, ll t1x, ll t1y, ll t2x, ll t2y) {
    return (x[p] - t2x) * (t1y - t2y) - (t1x - t2x) * (y[p] - t2y);
}

bool PointInTriangle (int pt, int t) {
    ll d1, d2, d3;
    bool has_neg, has_pos;

    d1 = sign(pt, tri[t][0], tri[t][1], tri[t][2], tri[t][3]);
    d2 = sign(pt, tri[t][2], tri[t][3], tri[t][4], tri[t][5]);
    d3 = sign(pt, tri[t][4], tri[t][5], tri[t][0], tri[t][1]);
    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

bool test(int id) {
    for(int i = 0; i < m; i++)
        if(PointInTriangle(id,i)) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    for(int i = 0; i < m; i++)
        for(int j = 0; j < 6; j++)
            cin >> tri[i][j];

    uniform_int_distribution<int> distribution(0,n-1);

    int ans = 0;
    int tot = min(R,n);

    for(int i = 0; i < min(R,n); i++) {
        int pos = distribution(rng);
        swap(x[pos], x[i]);
        swap(y[pos], y[i]);
    }

    for (int i = 0;i < min(R, n);i++) ans += test(i);
    double prob = (double)ans/tot;

    if(prob < eps) cout << 0;
    else if(prob < eps + 0.35) cout << 1;
    else if(prob < eps + 0.6) cout << 2;
    else if(prob < eps + 0.85) cout << 3;
    else cout << 4;
    cout << endl;

    return 0;
}

