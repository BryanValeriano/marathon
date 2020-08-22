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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 4e5+5;
vector<int> g[T];
ll in[T], l[T], m[T];
bool vis[T];

ll bfs(int n) {
    priority_queue<ii,vii> pq;
    for(int i = 1; i <= n; i++)
        if(!in[i]) pq.emplace(m[i],i);

    ll ans = 0;
    ll acum = 0;

    while(!pq.empty()) {
        ii at = pq.top();
        pq.pop();
        ans = max(ans,l[at.se] + acum);
        acum++;
        for(int v : g[at.se]) {
            in[v]--;
            if(!in[v]) pq.emplace(m[v],v);
        }
    }

    return ans;
}

int dfs(int u) {
    vis[u] = 1;
    m[u] = l[u];
    for(int v : g[u]) {
        if(!vis[v]) dfs(v);
        m[u] = max(m[u],m[v]);
    }
    return m[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> l[i];
        int k; cin >> k;
        in[i] += k;
        for(int j = 0; j < k; j++) {
            int x; cin >> x;
            g[x].pb(i);
        }
    }

    for(int i = 1; i <= n; i++)
        if(!in[i])
            dfs(i);

    cout << bfs(n) << endl;

    return 0;
}

