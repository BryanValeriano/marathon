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
int v[T];
int dp[T];
int n,m;

int solve(int at) {
    if(at >= n) return 0;
    if(dp[at] != -1) return dp[at];
    return dp[at] = max(solve(at+1), solve(at+m) + v[at]);
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> v[i];
    cout << solve(m) << endl;
    return 0;
}

