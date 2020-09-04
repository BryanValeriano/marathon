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
const int T = 5e3;
const int Z = 35;
const int OFF = T*2;
const int N = OFF*2+3;
vector<int> g[N];
int low[N], d[N], st[N], pai[N], peso[N];

int ids[4][Z][Z];
int lin[Z], col[Z];
int t, sz;

// lin    | dir  = 1 | esq  = 0
// col    | down = 1 | up   = 0

//              lin  |      col
// ids[0] |       0  |        0
// ids[1] |       0  |        1
// ids[2] |       1  |        0
// ids[3] |       1  |        1

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(peso[y] > peso[x]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
}

int neg(int x) {
    return (x > OFF? x - OFF : x + OFF);
}

void forceVar(int x) {
    g[neg(x)].pb(x);
    return;
}

void addOr(int x, int y) {
    g[neg(x)].pb(y);
    g[neg(y)].pb(x);
    return;
}

void addXor(int x, int y) {
    addOr(x,y);
    addOr(neg(x),neg(y));
    return;
}

void addImp(int x, int y) {
    //addXor(neg(x),y);
    g[x].pb(y);
    g[y].pb(x);
    g[neg(x)].pb(neg(y));
    g[neg(y)].pb(neg(x));
    return;
}

void tarjan(int u) {
    st[sz++] = u;
    low[u] = d[u] = ++t;

    for(int v : g[u]) {
        if(!low[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        } else low[u] = min(low[u],d[v]);
    }

    if(low[u] >= d[u]) {
        int a;
        do {
            a = st[--sz];
            join(u,a);
            d[a] = INF;
        } while(a != u);
    }
}

bool sat() {
    for(int i = 0; i < N; i++)
        if(!low[i]) tarjan(i);

    for(int i = 0; i < N; i++)
        if(find(i) == find(neg(i))) {
            cout << i << " | " << find(i) << " " << find(neg(i)) << endl;
            return false;
        }

    return true;
}

void print() {
    for(int i = 0; i < N; i++) {
        if(g[i].size()) cout << i << " | ";
        for(int j = 0; j < g[i].size(); j++)
            cout << g[i][j] << " ";
        if(g[i].size()) cout << endl;
    }
}

void bind() {
    for(int i = 0; i < Z; i++) {
        for(int j = 0; j < Z; j++) {
            for(int k = 0; k < 4; k++) {
                if(k&1) addImp(lin[i], ids[k][i][j]);
                else addImp(neg(lin[i]), ids[k][i][j]);
                if(k&2) addImp(col[j], ids[k][i][j]);
                else addImp(neg(col[j]), ids[k][i][j]);

                //for(int p = 0; p < N; p++) {
                //    pai[p] = p;
                //    peso[p] = 1;
                //    low[p] = d[p] = 0;
                //}
                //t = 0;
                //if(!sat()) {
                //    cout << k << " " << i << " " << j << endl;
                //    print();
                //    return;
                //}
            }
        }
    }
}

void reset() {
    for(int i = 0; i < N; i++) {
        g[i].clear();
        pai[i] = i;
        peso[i] = 1;
        low[i] = d[i] = 0;
    }
    t = 0;
    bind();
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;

    for(int i = 0; i < Z; i++) {
        lin[i] = ++cont;
        col[i] = ++cont;
        for(int k = 0; k < 4; k++)
            for(int j = 0; j < Z; j++)
                ids[k][i][j] = ++cont;
    }

    bool vis[N];
    memset(vis,0,sizeof vis);

    reset();
    cout << (sat()? "Yes1\n" : "No1\n");

    while(tc--) {
        int n,m,r;
        cin >> n >> m >> r;
        reset();
        for(int i = 0; i < r; i++) {
            int l1,c1,l2,c2; cin >> l1 >> c1 >> l2 >> c2;
            if(l1 == l2 and c1 == c2) continue;
            if(l1 == l2) {
                if(c1 < c2) forceVar(lin[l1]);
                else forceVar(neg(lin[l1]));
            }
            else if(c1 == c2) {
                if(l1 < l2) forceVar(col[c1]);
                else forceVar(neg(col[c1]));
            } else {
                int mask = 0;
                mask |= ((c1 < c2)? 1 : 0);
                mask |= ((l1 < l2)? 2 : 0);
                addOr(ids[mask][l1][c2], ids[mask][l2][c1]);
            }
        }
        cout << (sat()? "Yes\n" : "No\n");
    }

    return 0;
}
