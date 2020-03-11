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
const int T = 1e5 + 5;

int dist[T];
vector<int> g[T];
priority_queue<ii,vii, greater<ii>> fila;
int n,m;

void bfs(int alvo) {
    while(!fila.empty()) {
        ii x = fila.top();
        int at = x.se;

        if(at == alvo) return;
        fila.pop();
        if(x.fi > dist[at]) continue;
        bool flag = 0;

        for(int v : g[at]) {
            if(dist[v] > dist[at]+1) {
                dist[v] = dist[at]+1;
                fila.emplace(dist[v],v);
                if(v == alvo) flag = 1;
            }
        }

        if(flag) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(dist, INF, sizeof dist);

    cin >> n >> m;
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dist[1] = 0;
    fila.emplace(0,1);
    bfs(-1);

    int t,v;
    while(m--) {
        cin >> t >> v;
        if(t == 1) dist[v] = 0, fila.emplace(0,v);
        else {
            bfs(v);
            cout << dist[v] << endl;
        }
    }

    return 0;
}

