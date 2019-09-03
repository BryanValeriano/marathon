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

struct node {
    int x,y,d;
};

int n,m,d;

int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

bool isIn(int x, int y) {
    return (x >= 0 and x < n and y >= 0 and y < m);
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> d;
    char mat[n][m];
    bool vis[n][m];
    memset(vis, 0, sizeof vis);
    queue<node> fila;
    int inix, iniy;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == 'S') inix = i, iniy = j, vis[i][j] = 0;
            if(mat[i][j] == 'M') fila.push({i,j,0}), vis[i][j] = 1;
        }

    while(!fila.empty()) {
        node at = fila.front();
        fila.pop();
        if(at.d < d) {
            for(int k = 0; k < 4; k++) {
                int xx = at.x + mov[k][0];
                int yy = at.y + mov[k][1];
                if(isIn(xx,yy) and !vis[xx][yy]) fila.push({xx,yy,at.d+1}), vis[xx][yy] = 1;
            }
        }
    }

    if(!vis[inix][iniy]) fila.push({inix, iniy, 0});

    while(!fila.empty()) {
        node at = fila.front();
        fila.pop();
        if(mat[at.x][at.y] == 'F') { cout << at.d << endl; return 0; }
        for(int k = 0; k < 4; k++) {
            int xx = at.x + mov[k][0];
            int yy = at.y + mov[k][1];
            if(isIn(xx,yy) and !vis[xx][yy]) fila.push({xx,yy,at.d+1}), vis[xx][yy] = 1;
        }
    }

    cout << -1 << endl;

    return 0;
}

