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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    ll d, l , r;
    double v, vv, vy = 0;

    int n; cin >> n >> d >> v;

    for(int i = 0; i < n; i++) {
        cin >> l >> r >> vv;
        vy += (r-l) * vv;
    }

    vy /= d;

    vv = sqrt(v*v-vy*vy);

    if(fabs(vy) >= v or 2*vv < v) {
        cout << "Too hard" << endl;
    } else cout << fixed << setprecision(3) << d/vv << endl;

    return 0;
}

