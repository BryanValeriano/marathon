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

int n,m;
const int T = 110;
const int TT = 1e4 + 10;
int v[T];
int dp[T][TT];


int solve(int atual, int papel) {
    if(papel >= m) return 0;
    if(atual <= n) papel += v[atual];
    if(papel >= m) return 1;
    if(atual > n) return INF;

    int &r = dp[atual][papel];
    if(r != -1) return r;

    int k = 1;
    int ans = INF;
    ans = solve(atual+1, papel) + 1;
    for(int i = atual+1; i <= n; i++) {
        papel += max(0, v[i] - k++);
        ans = min(ans, solve(i+1, papel)+1);
    }
    return r = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> v[i];
    sort(v+1, v+1+n, greater<int>());
    memset(dp, -1, sizeof dp);
    int ans = solve(1, 0);
    cout << (ans >= INF? -1 : ans) << endl;
    return 0;
}

