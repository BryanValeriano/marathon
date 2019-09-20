#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF = 0x3f3f3f3f3f3f3f;
const double PI = acos(-1.0);

const int T = 2512;
vector<ii> g[T];
ll dist[T];
ll n,m,p;

void bellman() {
    for(int i = 0; i < n-1; i++)
        for(int u = 1; u <= n; u++)
            for(ii v : g[u])
                if(dist[u] < INF)
                    dist[v.fi] = min(dist[v.fi],dist[u]+v.se);
}

void cycle() {
    for(int i = 0; i < n-1; i++)
        for(int u = 1; u <= n; u++)
            for(ii v : g[u])
                if(dist[u] < INF and dist[u]+v.se < dist[v.fi])
                    dist[v.fi] = -INF;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> p;
    for(int i = 0; i < m; i++) {
        ll a,b,c;
        cin >> a >> b >> c;
        g[a].eb(b,p-c);
    }

    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[1] = 0;
    bellman();
    cycle();
    //bellman();

    cout << (dist[n] <= INF? -1 : dist[n] > 0? 0 : abs(dist[n])) << endl;
    return 0;
}

