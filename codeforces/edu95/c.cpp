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
const int T = 2e5+5;
int dp[2][T];
int vis[2][T];
int v[T];
int n,vez;

inline int solve(bool ok, int x) {
    if(x >= n) return 0;
    if(vis[ok][x] == vez) return dp[ok][x];
    vis[ok][x] = vez;
    return dp[ok][x] = min(solve(!ok,x+1)+(ok?v[x]-(x-1>=0?v[x-1]:0):0),
                    solve(!ok,x+2)+(ok?v[x+1]-(x-1>=0?v[x-1]:0):0));
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            if(i) v[i] += v[i-1];
        }
        for(int i = n; i < n+3; i++) v[i] = v[i-1];
        vez++;
        cout << solve(1,0) << endl;
    }
    return 0;
}

