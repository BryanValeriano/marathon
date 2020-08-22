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
const int T = 1e5+5;

int n;
ll s,t;
ll qtd[T],tmp[T];
vii g[T];

void dfs(int u, int p) {
    int ok = 1;
    for(ii e : g[u]) {
        if(e.fi != p) {
            tmp[e.fi] = e.se;
            dfs(e.fi,u);
            qtd[u] += qtd[e.fi];
            ok = 0;
        }
    }

    qtd[u] += ok;
    t += (qtd[u]*tmp[u]);
}

ll rem(int u) {
    ll x = (tmp[u]>>1) + (tmp[u]&1);
    return x*qtd[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        cin >> n >> s;
        for(int i = 1; i <= n; i++) g[i].clear(), qtd[i] = 0;
        for(int i = 0; i < n-1; i++) {
            int u,v,w;
            cin >> u >> v >> w;
            g[u].eb(v,w);
            g[v].eb(u,w);
        }

        t= 0;
        dfs(1,1);
        int ans = 0;
        priority_queue<ii,vii> pq;
        for(int i = 1; i <= n; i++)
            pq.emplace(rem(i),i);


        while(t > s) {
            ii at = pq.top();
            pq.pop();
            t -= at.fi;
            tmp[at.se] = (tmp[at.se]>>1);
            pq.emplace(rem(at.se),at.se);
            ans++;
        }

        cout << ans << endl;

    }
    return 0;
}

