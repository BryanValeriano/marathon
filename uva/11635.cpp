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
typedef pair<int,int> ii;
typedef tuple<int,int,int> i3;
typedef vector<ii> vii;
typedef vector<i3> vi3;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e4 + 3;
const int N = 602;

int n,h;
bitset<T> slp;
bool vis[T][N+2];
vii g[T];
vector<int> hot;

void init() {
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        for(int j = 0; j <= N; j++) vis[i][j] = 0;
    }
    for(int i = 0; i < h; i++) slp[hot[i]] = 0;
    hot.clear();
}

void read() {
    for(int i = 0; i < h; i++) {
        int x; cin >> x;
        hot.pb(x);
        slp[x] = 1;
    }
    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        int a,b,t;
        cin >> a >> b >> t;
        g[a].eb(b,t);
        g[b].eb(a,t);
    }
}

int dijkstra() {
    priority_queue<i3, vi3, greater<i3>  > pq;
    pq.emplace(0,0,1);

    while(!pq.empty()) {
        i3 at = pq.top();
        pq.pop();
        int d,s,u;
        tie(d,s,u) = at;

        if(vis[u][s]) continue;
        vis[u][s] = 1;
        if(u == n) return d;

        for(ii v : g[u]) {
            if(slp[u]) pq.emplace(d+1,v.se,v.fi);
            if(v.se + s <= 600) pq.emplace(d,s+v.se,v.fi);
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    while(n) {
        init();
        cin >> h;
        read();
        cout << dijkstra() << endl;
        cin >> n;
    }
    return 0;
}

