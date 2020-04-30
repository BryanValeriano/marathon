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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 12;
const int N = 1e3+2;
int n,m,k,p;
int a[T],b[T],c[T],d[T];
int dp[T][N];

int solve(int at, int sobra) {
    if((!sobra) or at == m) return 0;
    if(~dp[at][sobra]) return dp[at][sobra];
    dp[at][sobra] = 0;

    for(int i = 0; i*b[at] <= a[at] and i*c[at] <= sobra; i++)
        dp[at][sobra] = max(dp[at][sobra], solve(at+1,sobra-i*c[at])+i*d[at]);

    return dp[at][sobra];
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n >> m >> k >> p;
    for(int i = 0; i < m; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    int ans = 0;
    for(int i = 0; i*k <= n; i++)
        ans = max(ans, solve(0,n-i*k)+i*p);
    cout << ans << endl;
    return 0;
}

