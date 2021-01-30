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
typedef tuple<ll,ll,ll> ti;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct node {
    ll v[4];
    node() { v[0] = v[1] = v[2] = v[3] = 0; }
};

const int T = 1e5+2;
int crivo[T];
int ok[T];

node dp[T][3];
int vis[T][3];
int vez;

vii g[T];

void init() {
    for(ll i = 2; i < T; i++) {
        if(!crivo[i]) {
            ok[i] = 1;
            for(ll j = i+i; j < T; j += i) {
                crivo[j]++;
                if(crivo[j] == 2) {
                    if(!crivo[j/i]) ok[j] = 2;
                } else if(crivo[j] > 2) ok[j] = 0;
            }
        }
    }
}

node solve(int at, int p, int pai) {
    if(p > 2) return node();
    node &r = dp[at][p];
    if(vis[at][p] == vez) return r;
    vis[at][p] = vez;
    r = node();

    for(int i = 0; i < g[at].size(); i++) {
        if(g[at][i].fi == pai) continue;
        node L = solve(g[at][i].fi, p + g[at][i].se, at);
        node R = solve(g[at][i].fi, 0, at);
        r.v[3] += R.v[3];
        r.v[3] += r.v[1]*L.v[1];
        r.v[3] += r.v[2]*L.v[0] + r.v[0]*L.v[2];
        for(int j = 0; j < 4; j++) r.v[j] += L.v[j];
    }

    r.v[p]++;
    //cout << at << " " << p << endl;
    //for(int j =0; j < 4; j++) cout << r.v[j] << " ";
    //cout << endl;

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    init();
    freopen("evaluations.in","r",stdin);
    int t; cin >> t;
    int cont = 0;
    while(t--) {
        vez++;
        ll ans = 0;
        int n; cin >> n;
        for(int i = 1; i < n; i++) {
            int a,b,c; cin >> a >> b >> c;
            if(!ok[c] and c != 1) continue;
            g[a].eb(b,ok[c]);
            g[b].eb(a,ok[c]);
            //cout << a << " " << b << " " << ok[c] << endl;
        }

        for(int i = 1; i <= n; i++) {
            if(vis[i][0] != vez) {
                node x = solve(i,0,i);
                ans += x.v[2] + x.v[3];
            }
            g[i].clear();
        }



        cout << "Case " << ++cont << ": " << ans << endl;
    }
    return 0;
}

