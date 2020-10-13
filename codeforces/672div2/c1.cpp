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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 3e5+5;

ll dp[T][2];
int vis[T][2];
ll v[T];
int vez;
int n;

ll solve(int at, bool ok) {
    if(at >= n) return 0;
    if(vis[at][ok]==vez) return dp[at][ok];
    vis[at][ok] = vez;
    dp[at][ok] = max(solve(at+1,!ok)+(ok?-v[at]:v[at]), solve(at+1,ok));
    return dp[at][ok];
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int q; cin >> n >> q;
        for(int i = 0; i < n; i++) cin >> v[i];
        vez++;
        cout << solve(0,0) << endl;
    }
    return 0;
}

