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
const int T = 3e3+3;
const ll MOD = 998244353;
ll dp[T][T];
ll pre[T];
string s,t;
int n,m;


ll solve(int l, int r) {
    int pos = max(0,r-l-1);
    if(!l and r>m) {
        cout << pos << " --\n";
        return pre[n-pos];
    }
    if(dp[l][r] != -1) return dp[l][r];

    dp[l][r] = 0;

    if(l==r) {
        if(s[pos] == t[l]) dp[l][r] = (dp[l][r]+solve(l-1,r+1))%MOD;
    } else {
        if(s[pos] == t[l])
            dp[l][r] = (dp[l][r]+solve(l-1,r))%MOD;
        if(s[pos] == t[r])
            dp[l][r] = (dp[l][r]+solve(l,r+1))%MOD;
    }

    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    pre[0] = 1;
    for(int i = 1; i < T; i++) pre[i] = (2ll*pre[i-1])%MOD;
    cin >> s >> t;
    t = "#"+t;
    n = s.size();
    m = t.size()-1;
    t = t+"#";
    ll ans = 0;
    for(int i = 1; i <= m; i++) {
        ans = (ans+solve(i,i))%MOD;
        cout << i << " = " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}

