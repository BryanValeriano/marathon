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

const int T = 5e4 + 3;
const int N = 1e2 + 3;

int dp[N][T];
int vis[N][T];
int v[N];
int t,n,tot;

int solve(int at, int sum) {
    if(at == n) return abs(sum-(tot-sum));
    if(vis[at][sum] == t) return dp[at][sum];
    vis[at][sum] = t;
    return dp[at][sum] = min(solve(at+1,sum),solve(at+1,sum+v[at]));
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        t++;
        tot = 0;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> v[i], tot += v[i];
        cout << solve (0,0) << endl;
    }
    return 0;
}

