#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,ll> ii;
const ll INF = 0x3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

const int T = 202;
ll peso[T];
ll dist[T];
vector<ii> adj[T];

int n,m;

void bellmanFord() {
    for(int i = 0; i < n; i++)
        for(int u = 1; u <= n; u++)
            if(dist[u] < INF)
                for(ii v : adj[u])
                    dist[v.fi] = min(dist[v.fi], dist[u] + v.se);
}

void negCycle() {
    //for(int i = 0; i < n; i++)
        for(int u = 1; u <= n; u++)
            if(dist[u] < INF)
                for(ii v : adj[u])
                    if(dist[v.fi] > dist[u] + v.se)
                        dist[v.fi] = -INF;
}

ll ele(ll x) {
    return x*x*x;
}

int main() {
    ios_base::sync_with_stdio(false);
    int cont = 0;

    while(cin >> n) {
        for(int i = 1; i <= n; i++) {
            cin >> peso[i];
            dist[i] = INF;
            adj[i].clear();
        }

        cin >> m;
        for(int i = 0; i < m; i++) {
            int a,b; cin >> a >> b;
            adj[a].eb(b,ele(peso[b]-peso[a]));
        }

        dist[1] = 0;
        bellmanFord();
        negCycle();
        //bellmanFord();

        int q; cin >> q;
        cout << "Set #" << ++cont << endl;
        while(q--) {
            int a; cin >> a;
            if(dist[a] < 3 or dist[a] == INF or a > n) cout << '?' << endl;
            else cout << dist[a] << endl;
        }
    }

    return 0;
}

