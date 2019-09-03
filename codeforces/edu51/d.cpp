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
const int MOD = 998244353;
const int T = 1e3 + 3;
ll dp[T][2*T][5];
int n,k;

ll solve(int at, int c, int mask) {
    if(at == n) return (c == k);

    ll &r = dp[at][c][mask];
    if(r != -1) return r;
    r = 0;

    for(int i = 0; i <= 3; i++) {
        int l1 = (i & 1? 1 : 0); 
        int l2 = (i & 2? 1 : 0); 
        int d1 = ((mask & 1? 1 : 0) != l1);
        int d2 = ((mask & 2? 1 : 0) != l2); 
        int d = d1 + d2;
        if(at == 0) d = 2;
        if(d and l1 == l2) d--;

        r += solve(at+1, c+d, i);
    }

    r %= MOD;
    return r;
}



int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    cout << solve(0,0,0) << endl;
    return 0;
}

