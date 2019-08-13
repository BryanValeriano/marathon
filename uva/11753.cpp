#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e4 + 2;
const int K = 21;
int dp[T][K][K];
int vis[T][K][K];
int v[T];
int t;
int n,k;

int solve(int l, int k1, int k2) {
    int r = n-l-k1+k2+1;
    if(k1+k2 > 20) return INF;
    if(l >= r) return 0;

    int &d = dp[l][k1][k2];
    if(vis[l][k1][k2] == t) return d;

    if(v[l] == v[r]) d = solve(l+1, k1,k2);
    else d = min(solve(l+1, k1,k2+1), solve(l,k1+1,k2))+1;

    vis[l][k1][k2] = t;
    return d;
}

//int solve() {
//    for(int i = 1; i <= n; i++) dp[i][i] = 0;
//    for(int i = 0; i <= n; i++) dp[i][i+1] = (v[i] != v[i+1]);
//
//    for(int i = 2; i <= n; i++)
//        for(int j = 1; j+i <= n; j++) {
//            if(v[j] == v[j+i]) { dp[j][j+i] = dp[j+1][j+i-1]; continue; }
//            dp[j][j+i] = min(dp[j+1][j+i],dp[j][j+i-1])+1;
//        }
//
//    return dp[1][n];
//}
            

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    int cont = 0;

    while(tc--) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> v[i];
        t++;
        int ans = solve(1,0,0);
        cout << "Case " << ++cont << ": ";
        if(ans == 0) cout << "Too easy" << endl;
        else if(ans > k) cout << "Too difficult" << endl;
        else cout << ans << endl;
    }

    return 0;
}

