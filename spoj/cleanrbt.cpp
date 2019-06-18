#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 21;
const int N = 1025;
const int D = 401;

char mat[T][T];
int dp[D][N];
int vis[D][N];

int visit[D];
int dist[D][D];

int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
vector<int> ve;
vii vee;
int n, m, gol, vez;

bool isIn(int x, int y) {
    return(x >= 0 and x < n and y >= 0 and y < m);
}

int id(int x, int y) {
    return x*m + y;
}

void bfs(int x, int y) {
    vez++;
    int ori = id(x,y);
    queue< pair<ii,int> > fila;
    fila.emplace(ii(x,y),0);
    dist[ori][ori] = 0;
    visit[ori] = vez;

    while(!fila.empty()) {
        pair<ii,int> tmp = fila.front();
        int i = tmp.fi.fi;
        int j = tmp.fi.se;
        int d = tmp.se;
        fila.pop();

        for(int k = 0; k < 4; k++) {
            int ii = i + mov[k][0];
            int jj = j + mov[k][1];
            if(isIn(ii,jj) and mat[ii][jj] != 'x' and visit[id(ii,jj)] != vez) {
                dist[ori][id(ii,jj)] = dist[id(ii,jj)][ori] = d+1;
                fila.emplace(mk(ii,jj), d+1);
                visit[id(ii,jj)] = vez;
            }            
        }
    }
}
    
int solve(int at, int mask) {
    if(mask == gol) return 0;
    if(vis[at][mask] == vez) return dp[at][mask];
    
    int ans = INF;
    for(int i = 0; i < ve.size(); i++) 
        if(!(mask & (1<<i))) ans = min(ans, solve(ve[i], mask | (1<<i)) + dist[at][ve[i]]);

    vis[at][mask] = vez;
    return dp[at][mask] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> m >> n;

    while(n or m) {
        int ini;
        ve.clear();
        vee.clear();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> mat[i][j];
                if(mat[i][j] == 'o') ini = id(i,j);
                if(mat[i][j] == '*') ve.pb(id(i,j)), vee.eb(i,j);
            }
        }
   
        gol = pow(2,ve.size())-1;
        memset(dist, INF, sizeof dist);
        for(int i = 0; i < ve.size(); i++) bfs(vee[i].fi, vee[i].se);

        vez++;
        int ans = solve(ini,0);
        cout << (ans >= INF? -1 : ans) << endl;

        cin >> m >> n;
    }

    return 0;
}

