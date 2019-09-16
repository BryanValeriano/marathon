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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e3 + 3;
vector<int> g[T];
int cor[T];
bool vis[T];
int n,m,k;
int out = 1;
int corno;

bool bfs(int at) {
    queue<int> fila;
    vis[at] = 1;
    cor[at] = out;
    fila.push(at);

    while(!fila.empty()) {
        at = fila.front();
        fila.pop();

        for(int v : g[at]) {
            if(vis[v]) {
                if(cor[v] == cor[at]) cor[v] = corno;
            } else {
                cor[v] = (cor[at] == out? out+1 : out);
                vis[v] = 1;
                fila.push(v);
            }
        }
    }

    return 1;
}

bool check() {
    for(int i = 1; i <= n; i++) {
        if(cor[i] > k) return 0;
        if(g[i].size()) sort(g[i].begin(), g[i].end());
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            if(g[i].size() and binary_search(g[i].begin(), g[i].end(), j)) {
                if(cor[j] == cor[i]) return 0;
            } else if(cor[j] != cor[i]) return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    for(int i = 1; i <= n; i++)
        if(g[i].size() == (n-1)) { vis[i] = 1, cor[i] = out++; }

    corno = out+2;

    for(int i = 1; i <= n; i++) {
        if(!vis[i])  {
            if(!bfs(i)) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    if(!check()) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) cout << cor[i] << " ";
    cout << endl;

    return 0;
}
