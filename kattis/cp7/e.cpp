#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> ti;
typedef vector<ii> vii;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e3+2;
vector<int> v;
vti g[T];
int vis[T], dist[T];
int n,vez;

int dij(int at, int lo, int gol) {
    for(int i = 1; i <= n; i++) dist[i] = 0;
    dist[at] = INF;

    priority_queue<ii,vii> pq;
    pq.emplace(dist[at],at);

    while(!pq.empty()) {
        ii ok = pq.top();
        pq.pop();
        int d,u;
        tie(d,u) = ok;

        if(vis[u] == vez) continue;
        vis[u] = vez;
        if(u==gol) return d;

        for(ti e : g[u]) {
            int x,y,b;
            tie(x,y,b) = e;
            if(x > lo or y < lo) continue;
            int dd = min(d,y);
            if(dist[b] < dd) {
                dist[b] = dd;
                pq.emplace(dist[b],b);
            }
        }
    }

    return 0;
}

int solve(int s, int t) {
    int last = -1, ans = 0;
    for(int lo : v) {
        vez++;
        int hi = dij(s,lo,t);
        if(hi) {
            if(lo > last) ans += hi-lo+1;
            else if(hi >= last) ans += hi-last+1;
            last = max(hi+1,last);
        }
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    int m,b,s,t;
    cin >> n >> m >> b;
    cin >> s >> t;

    for(int i = 0; i < m; i++) {
        int a,b,x,y;
        cin >> a >> b >> x >> y;
        v.pb(x);
        g[a].eb(x,y,b);
    }
    sort(v.begin(), v.end());
    cout << solve(s,t) << endl;
    return 0;
}

