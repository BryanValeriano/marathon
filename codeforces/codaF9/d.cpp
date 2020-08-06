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
const int K = 21;
const int T = (1<<20);
ll dp[K][T];
string v[K];

int main() {
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int j = 0; j < m; j++) {
        int mask = 0;
        for(int i = 0; i < n; i++)
            if((v[i][j]=='1')) mask |= (1<<i);
        dp[0][mask]++;
    }

    int gol = (1<<n);

    for(ll k = 1; k <= n; k++) {
        for(int mask = 0; mask < gol; mask++) {
            if(k-2 >= 0) dp[k][mask] = (ll)(k-2-n)*dp[k-2][mask];
            for(int p = 0; p < n; p++) dp[k][mask] += dp[k-1][mask^(1<<p)];
            dp[k][mask] /= k;
        }
    }

    ll ans = INF;
    for(int mask = 0; mask < gol; mask++) {
        ll tmp = 0;
        for(ll k = 0; k <= n; k++) tmp += min(n-k,k)*dp[k][mask];
        ans = min(ans,tmp);
    }

    cout << ans << endl;

    return 0;
}

