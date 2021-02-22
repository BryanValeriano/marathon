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
const int T = 5e5+2;

vector<int> g[T];
int vis[T], until[T], t[T];
int n,m;

void fuc() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    while(m--) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    queue<int> fila;
    vector<int> ans;

    for(int i = 1; i <= n; i++) {
        cin >> t[i];
        if(t[i] == 1) {
            fila.emplace(i);
            vis[i] = 1;
        }
    }

    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();
        ans.pb(u);
        for(int v : g[u]) {
            if(t[v] == t[u]) fuc();
            if(vis[v]) continue;

            if(until[v]+1 == t[u]) until[v]++;
            if(until[v] == t[v]-1) {
                vis[v] = 1;
                fila.emplace(v);
            }
        }
    }

    if(ans.size() < n) cout << -1;
    else for(int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

