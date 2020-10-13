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
const int T = 1e6+5;

int n,m,sz,t;
bool c[T], isCycle[T],vis[T];
int g[T], ans, blk;
int low[T], st[T], d[T], pai[T], lin[T], len[T];
vector<int> h[T];
map<ii,int> used;

int id(int i, int j) { return i*m+j; }

void addEdg(int i, int j, char x) {
    int ii = i+(x=='U'?-1:x=='D'?1:0);
    int jj = j+(x=='L'?-1:x=='R'?1:0);
    g[id(i,j)] = id(ii,jj);
    h[id(ii,jj)].pb(id(i,j));
    //cout << id(i,j) << " -> " << id(ii,jj) << endl;
    //cout << "(" << i << ", " << j << ") -> ";
    //cout << "(" << ii << ", " << jj << ")\n";
}

void tarjan(int u) {
    st[sz++] = u;
    d[u] = low[u] = ++t;

    int v = g[u];

    if(!low[v]) {
        tarjan(v);
        low[u] = min(low[u],low[v]);
    } else low[u] = min(low[u],d[v]);

    if(low[u] >= d[u]) {
        int a;
        int ok = 0;
        do {
            a = st[--sz];
            pai[a] = u;
            d[a] = INF;
            isCycle[a] = 1;
            ok++;
        } while(a != u);

        if(ok==1) isCycle[a] = 0;
    }
}

void renum(int x) {
    int a = x;
    int aux = 0;
    do {
        vis[a] = 1;
        if(!c[a]) {
            used[mk(pai[a],aux)] = 1;
            blk++;
        }
        lin[a] = aux;
        aux++;
        len[pai[a]] = aux;
        a = g[a];
        ans++;
    }while(a != x);
}

void dfs(int u, int p, int aux, int dist) {
    vis[u] = 1;

    if(dist and !c[u]) {
        int ok = (aux-(dist%len[p])+len[p])%len[p];
        if(!used[mk(p,ok)]) {
            used[mk(p,ok)] = 1;
            blk++;
        }
    }

    for(int v : h[u])
        if(!vis[v])
            dfs(v,p,aux,dist+1);

}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ans = 0, blk = 0;
        used.clear();
        cin >> n >> m;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char x; cin >> x;
                int s = id(i,j);
                c[s] = (x-'0');
                vis[s] = low[s] = 0;
                h[s].clear();
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char x; cin >> x;
                addEdg(i,j,x);
            }
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!low[id(i,j)])
                    tarjan(id(i,j));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(isCycle[id(i,j)] and !vis[id(i,j)])
                    renum(id(i,j));

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(isCycle[id(i,j)])
                    dfs(id(i,j),pai[id(i,j)],lin[id(i,j)],0);

        cout << ans << " " << blk << endl;
    }
    return 0;
}

