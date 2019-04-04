#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 2e5 + 10;

struct node {
    int id, pos, ini, fim, val;

    bool operator < (const node &b) const {
        return ini < b.ini;
    }
};

int n;
vector<node> v;
vector<int> caminho;
int path[T];
int nxt[T];
int ind[T];
pll dp[T];

pll best(const pll &a, const pll &b) {
    if(a.fi > b.fi) return a;
    if(b.fi > a.fi) return b;
    if(a.se < b.se) return a;
    return b;
}

node empate(const node &a, const node &b) {
    if(a.pos < b.pos) return a;
    return b;
}

pll solve(int at) {
    if(at >= n) return pll(0,0);
    if(dp[at].fi != -1) return dp[at];

    pll pega = solve(nxt[at]);
    pll pula = solve(at+1);
    pega.fi += v[at].val;
    pega.se += (v[at].fim - v[at].ini);
    pll ans = best(pega,pula); 
    
    if(ans == pega) path[at] = nxt[at];
    else path[at] = 0;
    return dp[at] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    memset(dp, -1, sizeof dp);
    int a,b,c;

    for(int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        v.pb({i,0,a,b,c});
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        int prox = lower_bound(v.begin(), v.end(), node({0,0,v[i].fim,0,0})) - v.begin();
        v[i].pos = i;
        nxt[i] = prox;
        ind[i] = v[i].id;
    }
    
    for(int i = 0; i < n; i++) path[i];
    pll ans = solve(0);

    int ini;
    while(!path[ini] and ini < n) ini++;
    if(ini < n) caminho.pb(ind[ini]);

    while(ini < n) {
        ini = path[ini];
        if(ini == n) break;
        while(!path[ini] and ini < n) ini++;
        if(ini < n) caminho.pb(ind[ini]);
    }

    cout << caminho.size() << " " << ans.fi << " " << ans.se << endl;
    for(auto x : caminho) cout << x << " ";
    cout << endl;
        
    return 0;
}

