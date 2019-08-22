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
 
const int T = 1e6 + 2;
 
vii v;
vector<int> ve;
vector<int> g[T];
map<int,int> id;
ll dp[T][6];
int n;
 
ll solve(int at, int op) {
    if(at == ve.size()) return 0;
    if(dp[at][op] != -1) return dp[at][op];
 
    ll last;
    if(op == 0) last = g[at-1][1];
    if(op == 1) last = g[at-1][0];
    if(op == 2) last = g[at-1].back();
    if(op == 3) last = g[at-1][0];
    if(op == 4) last = g[at-1][g[at-1].size() - 2];
    if(op == 5) last = g[at-1].back();
 
    ll ok;
    for(int i = 0; i < 6; i++) {
        if(i == 0) {
            if(g[at].size() < 3) continue;
            ok = g[at][0];
        } else if(i == 1) {
            if(g[at].size() < 3) continue;
            ok = g[at][1];
        } else if(i == 2) {
            ok = g[at][0];
        } else if(i == 3) {
            ok = g[at].back();
        } else if(i == 4) {
            if(g[at].size() < 3) continue;
            ok = g[at].back();
        } else {
            if(g[at].size() < 3) continue;
            ok = g[at][g[at].size()-2];
        }
        dp[at][op] = max(dp[at][op], solve(at+1,i) + abs(ok-last)); 
    }
 
    return dp[at][op];
}
 
int main() {
    ios::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    cin >> n;
    int a,b;
 
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.eb(a,b);
        ve.pb(a);
    }
 
    sort(ve.begin(), ve.end());
    ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
    for(int i = 0; i < ve.size(); i++) id[ve[i]] = i;
 
    for(int i = 0; i < n; i++) g[id[v[i].fi]].pb(v[i].se);
    for(int i = 0; i < ve.size(); i++) sort(g[i].begin(), g[i].end()); 
 
    ll ans = 0;
 
    for(int i = 0; i < 6; i++) {
        if(g[0].size() < 3 and (i == 5 or i == 4 or i == 0 or i == 1)) continue;
        ans = max(ans,solve(1,i));
    }
 
    cout << ans << endl;
    
    return 0;
}
 
