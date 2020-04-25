#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const ll INF = 2e18;
const double PI = acos(-1.0);
const int T = 1002;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    while(n) {
        ll xi = -INF, yi = -INF, zi = -INF;
        ll xf = INF, yf = INF, zf = INF;

        for(int i = 0; i < n; i++) {
            ll x,y,z,d;
            cin >> x  >> y >> z >> d;
            xi = max(xi,x); yi = max(yi,y); zi = max(zi,z);
            xf = min(xf,x+d); yf = min(yf,y+d); zf = min(zf,z+d);
        }

        ll ans = (xf-xi)*(yf-yi)*(zf-zi);
        cout << ans << endl;
        cin >> n;
    }

    return 0;
}

