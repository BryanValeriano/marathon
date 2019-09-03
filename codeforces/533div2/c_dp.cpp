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
const int T = 2e5 + 10;
const int MOD = 1e9 + 7;
int n;
ll DIV[3];
ll dp[T][5];

ll solve(int atual, int rest) {
    if(atual == n) return (rest == 0);

    ll &r = dp[atual][rest];
    if(r != -1) return r;

    ll zero = (solve(atual + 1, rest) * DIV[0]) % MOD;
    ll um = (solve(atual + 1, (rest + 1) % 3) * DIV[1]) % MOD;
    ll dois = (solve(atual + 1, (rest + 2) % 3) * DIV[2]) % MOD;

    ll ans = (zero + um) % MOD;
    ans %= MOD;
    ans += dois;
    ans %= MOD;

    return r = ans;
}

int main() {
    ios::sync_with_stdio(false);
    int l,r;
    cin >> n >> l >> r;

    ll nl = l;
    ll nr = r;

    for(int i = l; i <= r; i++)
        if(i % 3 == 0) { nl = i; break; }
    for(int i = r; i >= l; i--) 
        if(i % 3 == 2) { nr = i; break; }

    DIV[0] = DIV[1] = DIV[2] = (nr - (nl-1))/3;

    for(int i = l; i < nl; i++)
        if(l != nl) DIV[i%3]++;
    for(int i = r; i > nr; i--)
        if(r != nr) DIV[i%3]++;
    
    if(DIV[0] == DIV[1] and DIV[1] == DIV[2] and DIV[0] == 0)
        for(int i = l; i <= r; i++)
            DIV[i%3]++;
    
    memset(dp, -1, sizeof dp);
    cout << solve(0,0) << endl;

    return 0;
}

