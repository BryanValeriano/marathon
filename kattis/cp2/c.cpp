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
typedef pair<ll,double> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = (1 << 16);

vii v;
double dp[T][17];
int vis[T][17];
ll base[17];
bool ok[T];
int n,c,m,vez;

double solve(int mask, int k) {
    if(k == c) return ok[mask];
    if(vis[mask][k] == vez) return dp[mask][k];

    double ans = 0;

    for(int i = 0; i < n; i++) {
        if(mask & (1<<i)) continue;
        ans = max(ans, solve(mask|(1<<i),k+1)*v[i].se + solve(mask|(1<<i),k)*(1-v[i].se));
    }

    vis[mask][k] = vez;
    return dp[mask][k] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;

    for(ll i = 1; i <= 16; i++)
        base[i] = (i == 1? i : 10ll*base[i-1]);

    while(tc--) {
        cin >> n >> c >> m;
        v.clear();

        for(int i = 0; i < n; i++) {
            int a,b; cin >> a >> b;
            v.eb(a,(double)b/100);
        }

        memset(ok,0,sizeof ok);

        for(int i = 1; i < (1 << n); i++) {
            int custo = 0;
            for(int j = 1, casa = 0; j < (1<<n); j <<= 1, casa++)
                if(i&j) custo += v[casa].fi;
            if(custo <= m) ok[i] = 1;
        }

        vez++;
        cout << fixed << setprecision(6) << solve(0,0) << endl;
    }


    return 0;
}

