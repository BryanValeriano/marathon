#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb  emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef pair<int,char> ic;
typedef vector<ic> vic;

const int INF = 0x3f3f3f3f;
const int T = 2e5 + 3;

vic g[T];
int dist[2][T];
bool vis[2][T];
vector<int> niv[T];
int pai[T];
int n,m;

void bfs(int x) {
    int pos = x==1;
    memset(dist[pos],INF,sizeof dist[pos]);
    dist[pos][x] = 0;
    vis[pos][x] = 1;
    queue<int> fila;
    fila.push(x);

    while(!fila.empty()) {
        int at = fila.front();
        fila.pop();
        for(ic nxt : g[at]) {
            int v = nxt.fi;
            if(!vis[pos][v]) {
                dist[pos][v] = dist[pos][at]+1;
                vis[pos][v] = 1;
                fila.push(v);
            }
        }
    }
}

void solve() {
    vector<int> ans;
    string ans2;
    int t = dist[1][n];

    niv[0].pb(1);

    for(int i = 0; i < t; i++) {
        char best = 'z';
        for(int tent : niv[i]) {
            for(auto k : g[tent]) {
                int v = k.fi;
                if(dist[1][v] != i+1 or dist[1][v]+dist[0][v] != t) continue;
                if(k.se < best) best = k.se;
            }

        }
        for(int tent : niv[i]) {
            for(auto k : g[tent]) {
                int v = k.fi;
                if(dist[1][v] != i+1 or dist[1][v]+dist[0][v] != t) continue;
                if(k.se == best and !pai[k.fi]) niv[i+1].pb(v), pai[k.fi] = tent;
            }

        }
        niv[i].clear();
        ans2 += best;
    }

    int x = n;
    while(x != 1) {
        ans.pb(x), x = pai[x];
        if(ans.size() > n+10) { cout << "FUCK" << endl; return; }
    }
    ans.pb(1);

    reverse(ans.begin(),ans.end());
    cout << ans.size()-1 << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
    cout << ans2 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a,b; char c;
        cin >> a >> b >> c;
        g[a].eb(b,c);
        g[b].eb(a,c);
    }

    bfs(1); bfs(n);
    solve();

    return 0;
}

