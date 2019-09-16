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
typedef pair<ii,int> wat;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector< vector<int> > g;
vector< vector<int> > vis;
map<ii,ii> pai;
int n,m;

int mov[2][2] = { {1,0}, {0,1} };

bool isIn(int x, int y) {
    return (x >= 1 and x <= n and y >= 1 and y <= m);
}

bool bfs() {
    queue<ii> pq;
    pq.emplace(1,1),
    vis[1][1] = 1;

    while(!pq.empty()) {
        ii at = pq.front();
        pq.pop();
        int x = at.fi;
        int y = at.se;

        for(int k = 0; k < 2; k++) {
            int xx = x + mov[k][0];
            int yy = y + mov[k][1];
            if(isIn(xx,yy) and !vis[xx][yy] and !g[xx][yy]) {
                vis[xx][yy] = 1;
                pq.emplace(xx,yy);
                pai[mk(xx,yy)] = mk(x,y);
                if(xx == n and yy == m) return 1;
            }
        }
    }
    return 0;
}

void pegaMin() {
    for(int i = 0; i <= n+1; i++)
        for(int j = 0; j <= m+1; j++)
            vis[i][j] = 0;

    ii at = pai[mk(n,m)];

    while(1) {
        if(at.fi == 1 and at.se == 1) break;
        vis[at.fi][at.se] = 1;
        at = pai[at];
    }

    //for(int i = 1; i <= n; i++) {
    //    for(int j = 1; j <= m; j++)
    //        cout << vis[i][j];
    //    cout << endl;
    //}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 0; i <= n+1; i++) {
        g.pb(vector<int>(m+3,0));
        vis.pb(vector<int>(m+3,0));
    }

    char ok;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> ok, g[i][j] = (ok == '#');
        }
    }

    if(!bfs()) { cout << 0 << endl; return 0; }
    pegaMin();
    bool x = !bfs();

    cout << ((g[1][2] or g[2][1] or g[n-1][m] or g[n][m-1] or x)? 1 : 2) << endl;

    return 0;
}

