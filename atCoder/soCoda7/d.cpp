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
const int T = 2e3 + 3;
const ll MOD = 1e9 + 7;

ll dp[T][T];
ll s[T], t[T];
int n,m;

ll solve(int i, int j) {
    if(j ==  m or i == n) return 0;

    ll &r = dp[i][j];
    if(~r) return r;

    r = 0;
    if(s[i] == t[j]) r = (solve(i+1,j+1)+1)%MOD;

    r = (r + solve(i+1,j)) % MOD;
    r = (r + solve(i,j+1)) % MOD;
    cout << i << " " << j << " " << r << endl;
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < m; i++) cin >> t[i];
    ll ans = (solve(0,0) + 1) % MOD;
    cout << ans << endl;
    return 0;
}

