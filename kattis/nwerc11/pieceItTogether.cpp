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
const int T = 503;
const int K = 4;
const int OFF = T*T*K*2;
const int N = OFF*2+5;

char v[T][T];
int ids[K][T][T], low[N], d[N], st[N], pai[N], peso[N];
int mov[4][2] = { {1,0}, {0, 1}, {-1,0} ,{0,-1} };
int n,m,cont,t,sz;
vector<int> g[N];

void init() {
    for(int i = 0; i < N; i++) {
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
    if(x==y) return;
    if(peso[y] > peso[x]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
}

void tarjan(int u) {
    st[sz++] = u;
    d[u] = low[u] = ++t;

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

bool isIn(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m);
}

int neg(int x) {
    return (x < OFF? x + OFF : x - OFF);
}

void addOr(int x, int y) {
    g[neg(x)].pb(y);
    g[neg(y)].pb(x);
}

void addXor(int x, int y) {
    addOr(x,y);
    addOr(neg(x), neg(y));
}

void force_var(int x) {
    g[neg(x)].pb(x);
}

bool sat() {
    for(int i = 1; i <= cont; i++)
        if(!low[i]) tarjan(i);
    for(int i = 1; i <= cont; i++)
        if(find(i) == find(neg(i))) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    init();
    bool ok = 1;
    int w = 0, b = 0;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> v[i][j];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 'B') {
                b++;
                for(int k = 0; k < K; k++) {
                    int ii = i + mov[k][0];
                    int jj = j + mov[k][1];
                    if(isIn(ii,jj) and v[ii][jj] == 'W') ids[k][i][j] = ++cont;
                    if(k>=2) {
                        if(ids[k][i][j] and ids[k-2][i][j]) addXor(ids[k][i][j], ids[k-2][i][j]);
                        else if(ids[k][i][j]) force_var(ids[k][i][j]);
                        else if (ids[k-2][i][j]) force_var(ids[k-2][i][j]);
                        else ok = 0;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 'W') {
                w++;
                vector<int> wtf;
                bool ok2 = 0;

                for(int k = 0; k < K; k++) {
                    int ii = i + mov[k][0];
                    int jj = j + mov[k][1];
                    if(isIn(ii,jj) and v[ii][jj] == 'B') {
                        wtf.pb(ids[(k+2)%4][ii][jj]);
                        ok2 = 1;
                    }
                }

                for(int ii = 0; ii < wtf.size(); ii++)
                    for(int jj = ii+1; jj < wtf.size(); jj++)
                        addOr(neg(wtf[ii]), neg(wtf[jj]));

                ok &= ok2;
            }
        }
    }

    ok &= sat();
    ok &= (b*2 == w);

    cout << (ok? "YES\n" : "NO\n");
    return 0;
}

