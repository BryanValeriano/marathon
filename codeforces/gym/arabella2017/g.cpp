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

const int T = 22;

ll n,m,k;
ll x[T];
ll y[T];

ll solve(int gol) {
    ll x1 = n;
    ll y1 = m;
    ll x2 = 0;
    ll y2 = 0;
    for(int i = 0; i < k; i++)
        if(gol & (1 << i)) {
            x1 = min(x[i],x1);
            y1 = min(y[i],y1);
            x2 = max(x[i],x2);
            y2 = max(y[i],y2);
        }

    return (x1*y1) * (n-x2+1) * (m-y2+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m >> k;
        for(int i = 0; i < k; i++) cin >> x[i] >> y[i];
        ll ans = ((n*(n+1)/2)) * ((m*(m+1)/2));
        int gol = pow(2,k)-1;
        for(int i = 1; i <= gol; i++) {
            if(__builtin_popcount(i)&1) ans -= solve(i);
            else ans += solve(i);
        }
        cout << ans << endl;
    }

    return 0;
}

