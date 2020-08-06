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
const int T = 3e3+4;
int dp[T][2];
int a[T], b[T], c[T];
int n;

int solve(int at, int mask) {
    if(at == n) return 0;
    if(~dp[at][mask]) return dp[at][mask];
    dp[at][mask] = solve(at+1,1)+(mask?b[at]:a[at]);
    if(at!=n-1) dp[at][mask] = max(dp[at][mask],solve(at+1,0)+(mask?c[at]:b[at]));
    return dp[at][mask];
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    cout << solve(0,0) << endl;
    return 0;
}

