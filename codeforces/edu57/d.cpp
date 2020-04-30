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
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int T = 1e5 + 10;
int n,cost[T];
ll dp[T][5];
string t = "hard";
string s;

ll solve(int at, int p) {
    if(p == 4) return INF;
    if(at == n) return 0;
    if(~dp[at][p]) return dp[at][p];
    ll ok = (s[at]==t[p]);
    dp[at][p] = min(solve(at+1,p+ok),solve(at+1,p)+cost[at]*ok);
    return dp[at][p];
}

void read() {
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> cost[i];
}

int main() {
    ios::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    read();
    cout << solve(0,0);
    return 0;
}

