//TLE

#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int T = 102;
const int N = 1e4 + 2;
int v[T];
int gol, n;

int dp[3*N];

inline int solve(int i, int tot, int qtd) {
    int &r = dp[tot];
    if(tot >= gol) return r = min(r, qtd);
    if(i == n) return INF;

    if(qtd >= r) return r;

    int ans = solve(i + 1, tot, qtd);
    ans = min(ans, solve(i + 1, tot + v[i], qtd+1));
    return r = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc; cin >> tc;
    while(tc--) {
        cin >> gol >> n;
        memset(dp, INF, sizeof dp);
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v, v+n, greater<int>());
        solve(0, 0, 0);
        for(int i = gol; i < 3*N; i++) 
            if(dp[i] != INF) { cout << i << " " << dp[i] << endl; break; }
    }
    return 0;
}

