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

const int T = 253;

char mat[T][T];
ll sum[T][T];
int vis[T][T];
vii source;
int n,m,q,p, v;

struct node {
    int x,y,c;
};

int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

bool isIn(int x, int y) {
    return (x >= 0 and x < n and y >= 0 and y < m);
}

void bfs(int x, int y) {
    v++;
    queue<node> fila;
    fila.push({x,y,(mat[x][y] - 'A' + 1)*q});
    vis[x][y] = v;
    while(!fila.empty()) {
        node at = fila.front();
        fila.pop();
        sum[at.x][at.y] += at.c;
        int nxt = at.c/2;
        if(!nxt) continue;
        for(int k = 0; k < 4; k++) {
            int xx = at.x + mov[k][0];
            int yy = at.y + mov[k][1];
            if(isIn(xx,yy) and vis[xx][yy] != v and mat[xx][yy] != '*') {
                vis[xx][yy] = v;
                fila.push({xx,yy,nxt});
            }
        }
    }
}

int count() { 
    int ans = 0;

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            ans += (sum[i][j] > p);

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> q >> p;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] >= 'A' and mat[i][j] <= 'Z') source.eb(i,j);
        }
    }

    for(auto z : source) 
        bfs(z.fi,z.se);

    cout << count() << endl;

    return 0;
}

