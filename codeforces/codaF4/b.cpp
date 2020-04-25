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
const int T = 1e5 + 3;
vector<int> g[T];
int pai[T];
ll peso[T];
ll n,m;

void init() {
    for(int i = 0; i <= n; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
}

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    init();
    vector<bool> vis(n+3);
    vii nodes;

    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        nodes.eb(x,i);
    }

    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    sort(nodes.begin(),nodes.end(),greater<ii>());
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        int u; ll c;
        tie(c,u) = nodes[i];
        set<int> bag;
        bag.insert(u);

        for(int v : g[u])
            if(vis[v]) bag.insert(find(v));

        ll tot = 0;
        for(auto v : bag) tot += peso[find(v)];
        for(auto v : bag) {
            ans += (tot-peso[find(v)])*peso[find(v)]*c;
            tot -= peso[find(v)];
        }
        for(auto v : bag) join(find(v),find(u));
        vis[u] = 1;
    }

    cout << fixed << setprecision(4);
    cout << (double)ans/(n*(n-1)>>1) << endl;
    return 0;
}

