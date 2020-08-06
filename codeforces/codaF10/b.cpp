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
const int T = 202;
const int K = 1e3+2;
const ll MOD = 1e9+7;
int dp[T][T][K];
int v[T];
int sum[T];
int n,k;

ll solve(int at, int open, int used) {
    used += open*sum[at];
    if(used > k) return 0;
    if(at == n) return (open==0);
    if(~dp[at][open][used]) return dp[at][open][used];
    ll r = 0;

    //open
    r += solve(at+1,open+1,used);
    //alone
    r += solve(at+1,open,used);

    if(open) {
        //close
        r += solve(at+1,open-1,used)*(ll)open;
        //put
        r += solve(at+1,open,used)*(ll)open;
    }

    return dp[at][open][used] = r%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v,v+n);
    for(int i = 1; i < n; i++) sum[i] = v[i]-v[i-1];
    cout << solve(0,0,0) << endl;
    return 0;
}

