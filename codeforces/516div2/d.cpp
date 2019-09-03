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
const int T = 2010;
char mat[T][T];
int trackx[T][T];
int tracky[T][T];
int n,m;

int mov[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

bool isIn(int i, int j) {
    return (i >= 1 and i <= n and j >= 1 and j <= m);
}

void dfs(int x, int y, int limx, int limy) {
    trackx[x][y] = max(trackx[x][y], limx);
    tracky[x][y] = max(tracky[x][y], limy);
    mat[x][y] = 'x';

    for(int k = 0; k < 4; k++) {
        int xx = mov[k][0] + x;
        int yy = mov[k][1] + y;
        if(isIn(xx,yy) and mat[xx][yy] != '*') {
            if((limx > trackx[xx][yy] or limy > tracky[xx][yy]) and (mov[k][1] == 0))
                dfs(xx,yy, limx,limy);

            else if((limx-1 > trackx[xx][yy] or limy > tracky[xx][yy]) and (mov[k][1] == -1 and limx >= 1))
                dfs(xx,yy, limx-1, limy);
           
            else if((limx > trackx[xx][yy] or limy-1 > tracky[xx][yy]) and (mov[k][1] == 1 and limy >= 1))
                dfs(xx,yy, limx, limy-1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int startx, starty, x, y;
    int ans = 0;
    cin >> n >> m;
    cin >> startx >> starty;
    cin >> x >> y;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> mat[i][j];

    memset(trackx, -2, sizeof trackx);
    memset(tracky, -2, sizeof tracky);
    dfs(startx, starty, x, y);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mat[i][j] == 'x') ans++;
            //cout << mat[i][j];
        }
        //cout << endl;
    }

    cout << ans << endl;

    return 0;
}

