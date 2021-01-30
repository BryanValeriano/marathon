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
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 102;
int g[T][T];
bool vis[T][T];
int n,m,ans;
vector<int> r;

void init(bool ok) {
    for(int i = 0 ; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(ok) g[i][j] = INF;
            dist[i][j] = INF;
            pai[i][j] = -1;
            vis[i][j] = 0;
        }
    }
    if(ok) {
        ans = INF;
        r.clear();
    }
}

vector<int> getPath(int a, int q) {
    vector<int> tmp;
    while(q) {
        tmp.pb(a);
        a = pai[a][q--];
    }
    return tmp;
}

void dij(int o) {
    init(0);
    dist[o][0] = 0;
    priority_queue<ti,vti,greater<ti>> pq;
    pq.emplace(dist[o][0],o,0);

    while(!pq.empty()) {
        //auto [d,u,q] = pq.top();
        int d,u,q;
        tie(d,u,q) = pq.top();
        pq.pop();
        if(vis[u][q] or q > n) continue;
        vis[u][q] = 1;

        for(int v = 1; v <= n; v++) {
            if(dist[v][q+1] > d+g[u][v] and v != pai[u][q]) {
                pai[v][q+1] = u;
                dist[v][q+1] = d+g[u][v];
                e[u][v] = e[v][u] = 1;
                pq.emplace(dist[v][q+1],v,q+1);
            }
        }
    }

    for(int j = 3; j <= n; j++) {
        if(dist[o][j] < ans) {
            r = getPath(o,j);
            ans = dist[o][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    while(n != -1) {
        cin >> m;
        init(1);
        while(m--) {
            int x,y,l; cin >> x >> y >> l;
            g[x][y] = g[y][x] = min(g[x][y],l);
        }
        for(int i = 1; i <= n; i++) dij(i);
        if(ans == INF) cout << "No solution.\n";
        else {
            for(int i = 0; i < r.size(); i++)
                cout << r[i] << (i+1<r.size()? ' ' : '\n');
            //cout << "algo " << ans << " " << r.size() << endl;
        }
        cin >> n;
    }
    return 0;
}

