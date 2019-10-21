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

const int T = 55;
const int N = 255;
ll dp[T][N];
int v[T];
int n,m;

ll solve(int at, int sum) {
    if(sum == n) return 1;
    if(sum > n or at >= m) return 0;
    if(~dp[at][sum]) return dp[at][sum];

    ll ans = 0;
    for(int i = 0; sum + v[at]*i <= n; i++)
        ans += solve(at+1,sum+v[at]*i);

    return dp[at][sum] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n >> m;
    for(int i = 0; i < m; i++) cin >> v[i];
    cout << solve(0,0) << endl;
    return 0;
}

