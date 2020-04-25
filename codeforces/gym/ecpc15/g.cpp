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
typedef pair<ll,int> ii;
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5 + 3;
int n,m,k;
vti g[T];
ll cost[T];
bool vis[T];

void init(int n) {
    for(int i = 0; i <= n; i++) {
        g[i].clear();
    }
}

bool reach(int wisdom) {
    for(int i = 1; i <= n; i++) cost[i] = INF, vis[i] = 0;
    cost[1] = 0;
    priority_queue<ii,vii,greater<ii>> pq;
    pq.emplace(0,1);

    while(!pq.empty()) {
        auto at = pq.top();
        pq.pop();
        int u = at.se;
        ll c = at.fi;

        if(vis[u]) continue;
        if(u == n) return 1;
        vis[u] = 1;

        for(auto nxt : g[u]) {
            ll v,d,w;
            tie(v,d,w) = nxt;
            if(cost[v] > cost[u] + d and w <= wisdom and cost[u]+d < k) {
                cost[v] = cost[u]+d;
                pq.emplace(cost[v],v);
            }
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m >> k;
        init(n);

        for(int i = 0; i < m; i++) {
            int a,b,w,c;
            cin >> a >> b >> c >> w;
            g[a].eb(b,c,w);
            g[b].eb(a,c,w);
        }

        int l = 0;
        int r = 1e9;
        int ans = -1;

        while(l<=r) {
            int mid = (l+r) >> 1;
            if(reach(mid)) ans = mid, r = mid-1;
            else l = mid+1;
        }

        cout << ans << endl;
    }
}

