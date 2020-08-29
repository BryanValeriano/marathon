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
typedef pair<int,int> i2;
typedef tuple<int,int,int> ti;
typedef vector<i2> vii;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e4+5;
int dist[2][2][11][T];
bool vis[2][2][11][T];
vii g[2][T];
int k;

void dij(int ori, bool op, bool op2) {
    dist[op][op2][0][ori] = 0;
    priority_queue<ti,vti,greater<ti>> pq;
    pq.emplace(0,0,ori);

    while(!pq.empty()) {
        int d,use,u;
        tie(d,use,u) = pq.top();
        pq.pop();

        if(vis[op][op2][use][u]) continue;
        vis[op][op2][use][u] = 1;

        for(i2 e : g[op2][u]) {
            int v,dd;
            tie(v,dd) = e;
            if(d+dd < dist[op][op2][use][v]) {
                dist[op][op2][use][v] = d+dd;
                pq.emplace(d+dd,use,v);
            }
            if(use+1 <= k and d < dist[op][op2][use+1][v]) {
                dist[op][op2][use+1][v] = d;
                pq.emplace(d,use+1,v);
            }
        }
    }

    return;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    int a,b,n,m;
    int u,v,w,ans;

    cin >> n >> m;
    cin >> a >> b >> k;

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            for(int s = 0; s <= k; s++)
                for(int p = 0; p < n; p++)
                    dist[i][j][s][p] = INF;

    while(m--) {
        cin >> u >> v >> w;
        g[0][u].eb(v,w);
        g[1][v].eb(u,w);
    }

    dij(a,0,0);
    dij(a,0,1);
    dij(b,1,0);
    dij(b,1,1);

    ans = INF;

    for(int i = 0; i <= k; i++) {
        for(int ii = 0; ii+i <= k; ii++) {
            for(int j = 0; j <= k; j++) {
                for(int jj = 0; jj+j <= k; jj++) {
                    for(int p = 0; p < n; p++) {
                        if(p == a or p == b) continue;
                        int d = dist[0][0][i][p] + dist[0][1][ii][p] + dist[1][0][j][p] + dist[1][1][jj][p];
                        if(ans > d) ans = d, u = p;
                        else if(ans == d) u = min(u,p);
                    }

                }
            }
        }
    }

    if(ans==INF) cout << ">:(\n";
    else cout << u << " " << ans << endl;

    return 0;
}
