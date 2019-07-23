#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 3e5  +2;
ll dp[T][3][11];
ll v[T];
ll n, m, k;

ll solve(int at, int pega, int mod) {
    if(at == n or pega == 2) return 0;
    ll &r = dp[at][pega][mod];
    if(r != -1) return r;

    if(pega == 0) r = max(solve(at+1, 1, 1) + v[at] - k, solve(at+1,0,0));
    else if(pega == 1) {
        ll wtf = v[at];
        if(mod == m) wtf -= k, mod=0;
        r = max(solve(at+1,1,mod+1) + wtf, solve(at+1,2,0));
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << max(0LL, solve(0,0,0)) << endl;
    return 0;
}

