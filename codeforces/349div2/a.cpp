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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    double d,h,v,e;
    cin >> d >> h >> v >> e;

    double l = 0;
    double r = 1e4+10;
    double ans = r;

    for(int i = 0; i < 100; i++) {
        double mid = (l+r)/2;
        double vol2 = (d/2)*(d/2)*PI*(h+e*mid) - (mid*v);
        if(vol2 <= 0) ans = mid, r = mid;
        else l = mid;
    }

    if(ans > 1e4) cout << "NO" << endl;
    else cout << "YES" << endl << fixed << setw(4) << ans << endl;

    return 0;
}

