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
const int T = 20;
const int N = 1e6;
int v[T];
int rules[T][T];
int n, m, k;
ll dp[T][N];

ll brute(int atual, ll mask, int full) {
    if(full == m) return 0;

    ll &r = dp[atual][mask];
    if(r != -1) return r;
    
    ll ans = 0;
    for(int i = 1; i <= n; i++) 
        if(!(mask & (1<<i))) 
            ans = max(ans, brute(i, mask | (1<<i), full+1) + v[i] + rules[atual][i]);

    return r = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    int a,b,c;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 0; i < k; i++) {
        cin >> a >> b >> c;
        rules[a][b] = c;
    }
    memset(dp, -1, sizeof dp);
    ll ans = 0;
    for(int i = 1; i <= n; i++) 
        ans = max(ans, brute(i, 0 | (1<<i),1) + v[i]);

    cout << ans << endl;
    return 0;
}
