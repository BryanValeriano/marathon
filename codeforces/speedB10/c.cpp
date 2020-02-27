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
const ll INF = 1e17;
const double PI = acos(-1.0);
const int T = 103;

int n,m,k;
ll p[T][T];
ll v[T];
ll dp[T][T][T];

ll solve(int at, int last, int g) {
    if(at == n) return (g == k? 0 : INF);

    ll &r = dp[at][last][g];
    if(r != -1) return r;

    r = INF;

    if(v[at]) r = solve(at+1,v[at],g+(v[at] != last));

    else {
        for(int i = 1; i <= m; i++) {
            r = min(r, solve(at+1,i,g+(i != last)) + p[at][i]);
        }
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> v[i];

    for(int i = 0; i < n; i++)
        for(int j = 1; j <= m; j++)
            cin >> p[i][j];

    ll ans = solve(0,0,0);
    cout << (ans >= INF? -1 : ans) << endl;

    return 0;
}

