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
typedef tuple<int,int,int> ti;
typedef vector<ii> vii;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5+5;

int n,m;
vti e;
vector<int> g[T];
vector<int> ans;
int pai[T], dist[T], best[T];
bool vis[T];

void addEdge(int x, int y, int z) {
    g[x].pb(e.size());
    g[y].pb(e.size());
    e.eb(x,y,z);
}

void bfs(int u) {
    queue<int> fila;
    fila.push(u);
    dist[u] = 1;
    while(!fila.empty()) {
        u = fila.front();
        fila.pop();
        for(int s : g[u]) {
            int x,y,z;
            tie(x,y,z) = e[s];
            if(y==u) swap(x,y);
            if(!dist[y] or (dist[y]==dist[u]+1 and best[u]+(!z) < best[y])) {
                if(!dist[y]) fila.push(y);
                dist[y] = dist[u]+1;
                best[y] = best[u]+(!z);
                pai[y] = s;
            }
        }
    }
}

void makePath() {
    int u = n;
    do {
        int x,y,z;
        tie(x,y,z) = e[pai[u]];
        vis[pai[u]] = 1;
        if(u==y) swap(x,y);
        if(!z) ans.pb(pai[u]);
        u = y;
    } while(u != 1);
}

void rest() {
    for(int i = 0; i < m; i++) {
        if(!vis[i] and get<2>(e[i])) {
            ans.pb(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x,y,z; cin >> x >> y >> z;
        addEdge(x,y,z);
    }

    bfs(1);
    makePath();
    rest();

    cout << ans.size() << endl;
    for(int x : ans)
        cout << get<0>(e[x]) << " " << get<1>(e[x]) << " " << (!get<2>(e[x])) << endl;

    return 0;
}

