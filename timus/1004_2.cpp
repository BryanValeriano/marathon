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
int g[T][T], pai[T][T][T], dist[T][T][T];
int n,m,ans;
vector<int> r;

void init(bool ok) {
    for(int i = 0 ; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(ok) g[i][j] = INF;
            for(int k = 0; k <= n; k++) {
                dist[i][j][k] = INF;
                pai[i][j][k] = -1;
            }
        }
    }
    if(ok) {
        ans = INF;
        r.clear();
    }
}

vector<int> getPath(int q, int p) {
    vector<int> tmp;
    int o = p;
    while(q) {
        tmp.pb(p);
        p = pai[q--][o][p];
    }
    return tmp;
}

void solve() {
    for(int i = 1; i <= n; i++)
        dist[0][i][i] = 0;

    for(int q = 0; q < n; q++) {
        for(int p = 1; p <= n; p++) {
            for(int u = 1; u <= n; u++) {
                for(int v = 1; v <= n; v++) {
                    if(dist[q+1][p][v] > dist[q][p][u]+g[u][v] and v != pai[q][p][u]) {
                        pai[q+1][p][v] = u;
                        dist[q+1][p][v] = dist[q][p][u]+g[u][v];
                    }
                }
            }
        }
    }

    int qq = -1, pp = -1;

    for(int q = 3; q <= n; q++) {
        for(int p = 1; p <= n; p++) {
            if(dist[q][p][p] < ans) {
                ans = dist[q][p][p];
                qq = q, pp = p;
            }
        }
    }

    if(qq != -1) r = getPath(qq,pp);
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
        solve();
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

