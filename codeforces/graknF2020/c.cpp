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
double eps = 1e-9;
const int T = 1e5+5;
ll v[T];
ll f,n;

double left(double mid) {
    double vel = 1;
    ll at = 0;

    for(int i = 0; i < f; i++) {
        double cost = (v[i]-at)/vel;
        if(mid-cost < eps) break;
        mid -= cost;
        at = v[i];
        vel++;
    }

    return min((double)n,at+mid*vel);
}

double right(double mid) {
    double vel = 1;
    ll at = n;

    for(int i = f-1; i >= 0; i--) {
        double cost = (at-v[i])/vel;
        if(mid-cost < eps) break;
        mid -= cost;
        at = v[i];
        vel++;
    }

    return max(0.0,at-mid*vel);
}

bool check(double mid) {
    double pos = left(mid);
    double pos2 = right(mid);
    //cout << mid << " " << pos << " " << pos2 << endl;
    return pos >= pos2+eps;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> f >> n;
        for(int i = 0; i < f; i++) cin >> v[i];

        double l = 0;
        double r = n+2;
        double ans = r;

        for(int k = 0; k < 65; k++) {
            double mid = (l+r)/2;
            if(check(mid)) ans = mid, r = mid-1;
            else l = mid+1;
        }

        cout << fixed << setprecision(6) << ans << endl;
    }
    return 0;
}

