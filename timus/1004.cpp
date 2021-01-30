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

const int INF = 1e6;
const double PI = acos(-1.0);
const int T = 102;
int g[T][T], pai[T], dist[T];
bool vis[T];
int n,m,ans;
vector<int> r;

void init(bool ok) {
    for(int i = 0 ; i <= n; i++) {
        dist[i] = INF;
        pai[i] = -1;
        vis[i] = 0;
        for(int j = 0; j <= n; j++) {
            if(ok) g[i][j] = INF;
        }
    }
    if(ok) {
        ans = INF;
        r.clear();
    }
}

vector<int> getPath(int a, int b, int o) {
    vector<int> tmp;
    vector<int> tmp2;
    while(a != -1) {
        tmp.pb(a);
        a = pai[a];
    }
    while(b != o) {
        tmp2.pb(b);
        b = pai[b];
    }
    while(tmp2.size()) tmp.pb(tmp2.back()), tmp2.pop_back();
    return tmp;
}

void dij(int o) {
    init(0);
    dist[o] = 0;
    priority_queue<ii,vii,greater<ii>> pq;
    pq.emplace(dist[o],o);

    while(!pq.empty()) {
        //auto [d,u,q] = pq.top();
        int d,u;
        tie(d,u) = pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;

        for(int v = 1; v <= n; v++) {
            if(dist[v] > d+g[u][v] and v != pai[u]) {
                pai[v] = u;
                dist[v] = d+g[u][v];
                pq.emplace(dist[v],v);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(i == o) continue;
        for(int j = i+1; j <= n; j++) {
            if(j == o or pai[j] == i or pai[i] == j) continue;
            //cout << i << " " << o << " " << j << " = ";
            //cout << dist[i] << " " << g[i][j] << " " << dist[j] << endl;
            if(ans > g[i][j] + dist[i] + dist[j]) {
                ans = g[i][j]+dist[i]+dist[j];
                r = getPath(i,j,o);
            }
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

