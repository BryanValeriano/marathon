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
const ll INF = 0x3f3f3f3f3f3f3f;

const int T = 5e4 + 5;
ll v[T];
ll dp[T][5];
int escolha[T][5];
int n;
 
ll solve(int at, int p) {
    if(at == n) return (p == 3? 0 : -INF);
    ll &r = dp[at][p];
    if(r != -1) return r;
    
    ll x = (p&1? -v[at] : v[at]);
    ll k = solve(at+1,p) + x;
    ll t = -INF;
    if(p < 3) t = solve(at+1,p+1) + x;

    ll ans = max(k,t);

    if(k >= t) escolha[at][p] = 0;
    else escolha[at][p] = 1;

    return r = ans;
}

void build(int at, int p) {
    if(at >= n) return;
    if(escolha[at][p]) cout << at+1 << " ";
    build(at+1, p + escolha[at][p]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) cin >> v[i];
    
    ll ans = 0;
    ll k = 0;
    int ini = 0;

    for(int i = 0; i < 4; i++) {
        k = solve(0,i);
        if(k >= ans) ini = i;
        ans = max(ans, k);
    }

    for(int i = 0; i < ini; i++) cout << 0 << " ";
    build(0,ini);
    cout << endl;
    
    return 0;
}

