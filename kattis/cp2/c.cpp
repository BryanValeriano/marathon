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
typedef pair<ll,__int128> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = (1 << 16);

vii v;
__int128 dp[T];
ll cost[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    int n,c,m;
    while(tc--) {
        cin >> n >> c >> m;
        v.clear();

        __int128 base = 1;
        for(int i = 0; i < c; i++) base *= (__int128)100;

        for(int i = 0; i < n; i++) {
            int a,b; cin >> a >> b;
            v.eb(a,b);
        }

        int gol = (1 << n);
        long double ans = 0;

        memset(cost, 0, sizeof cost);
        memset(dp, 0, sizeof dp);
        dp[0] = 1;

        for(int i = 1, casa = 0; i < gol; i <<= 1, casa++)
            for(int j = 0; j < gol; j++) {
                if(i & j) continue;
                dp[j|i] = dp[j]*v[casa].se;
                cost[j|i] += v[casa].fi;
                //cout << (j|i) << " " << cost[j|i] << endl;
            }

        for(int i = 0; i < gol; i++) {
            //cout << i << " ";
            //cout << __builtin_popcount(i) << " ";
            //cout << cost[i] << endl;
            if(__builtin_popcount(i) != c or cost[i] > m) continue;
            ans = max(ans, (long double)dp[i]/(long double)base);
        }


        cout << fixed << setprecision(6) << ans << endl;
    }


    return 0;
}

