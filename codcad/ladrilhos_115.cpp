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
const int T = 210;
int n, m;
int g[T][T];
bool vis[T][T];
int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

bool isIn(int x, int y) {
    return(x >= 0 and x < n and y >= 0 and y < m);
}

int dfs(int x, int y) {
    vis[x][y] = true;
    int acum = 0;

    for(int k = 0; k < 4; k++) {
        int xx = x + mov[k][0];
        int yy = y + mov[k][1];
        if(isIn(xx,yy) and !vis[xx][yy] and g[x][y] == g[xx][yy])
            acum += dfs(xx,yy) + 1;
    }
    return acum;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];

    int mini = INF;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            if(!vis[i][j]) 
                mini = min(mini, dfs(i,j) + 1);
    cout << mini << endl;
    return 0;
}

