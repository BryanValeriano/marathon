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
const ll INF = 0x3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    ll k,p,x; cin >> k >> p >> x;
    double ans = INF;
    for(ll i = 1; i <= k+10000; i++) {
        ll contratar = i*x;
        double dias = (double)k/i;
        dias *= p;
        ans = min(ans,contratar+dias);
    }
    cout << fixed << setprecision(3) << ans << endl;
    return 0;
}

