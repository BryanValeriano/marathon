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
typedef tuple<ll,ll,ll> ti;
typedef vector<ti> vti;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5+5;

int n;
ll s,t;
ll qtd[T],tmp[T],cost[T];
vti g[T];

void dfs(int u, int p) {
    int ok = 1;

    for(ti e : g[u]) {
        ll v,w,c;
        tie(v,w,c) = e;
        if(v != p) {
            tmp[v] = w;
            dfs(v,u);
            qtd[u] += qtd[v];
            cost[v] = c;
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
            int u,v,w,c;
            cin >> u >> v >> w >> c;
            g[u].eb(v,w,c);
            g[v].eb(u,w,c);
        }

        t = 0;
        dfs(1,1);
        int ans = 0;

        priority_queue<ii,vii> pq;
        priority_queue<ii,vii> pq2;

        for(int i = 1; i <= n; i++) {
            if(cost[i] == 1) pq.emplace(rem(i),i);
            else pq2.emplace(rem(i),i);
        }

        while(t > s) {
            ii at = mk(0,0);
            ii at2 = mk(0,0);

            if(!pq.empty()) at = pq.top();
            if(!pq2.empty()) at2 = pq2.top();

            //cout << at.fi << " " << at.se << endl;
            //cout << at2.fi << " " << at2.se << endl;
            //cout << " --------------- " << endl;

            if(at.fi > at.se*2) {
                pq.pop();
                t -= at.fi;
                tmp[at.se] = (tmp[at.se]>>1);
                pq.emplace(rem(at.se),at.se);
                ans++;
            } else {
                pq2.pop();
                t -= at2.fi;
                tmp[at2.se] = (tmp[at2.se]>>1);
                pq2.emplace(rem(at2.se),at2.se);
                ans += 2;
            }

            //cout << t << " | " << s << " x " << ans << endl;
        }

        cout << ans << endl;

    }
    return 0;
}

