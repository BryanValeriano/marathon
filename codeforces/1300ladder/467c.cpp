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
const int T = 5e3 + 3;
ll v[T];
ll dp[T][T];
int n, m, k;


ll solve(int i, int j) {
    if(i == n) return 0;
     
    ll &r = dp[i][j];
    if(r != -1) return r;
    
    ll ans = 0;
    if(i+m-1 < n and j+1 <= k)
        ans = solve(i+m, j+1) + v[i+m-1] - (i-1 >= 0? v[i-1] : 0);
    ans = max(ans, solve(i+1, j));
    return r = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 1; i < n; i++)
        v[i] += v[i-1];
    cout << solve(0,0) << endl;
    return 0;
}
