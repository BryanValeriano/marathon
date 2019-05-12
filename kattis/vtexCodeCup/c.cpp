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

const int T = 1e3 + 5;
char mat[T][T];
int vis[T][T];
int ans[T][T];
int n, m, v;
int caldax, calday;
ll tot;
bool flag;

int dfs(int x, int y, int movs) {
    if(x < 0 or x >= n or y < 0 or y >= m) return 0;
    if(vis[x][y] == v) { caldax = x, calday = y, flag = true; return movs - ans[x][y]; }
    if(vis[x][y]) { flag = false; return ans[x][y]; }

    vis[x][y] = v;
    ans[x][y] = movs;
    movs++;
    int z = 0;

    if(mat[x][y] == 'N') z = dfs(x-1,y,movs); 
    else if(mat[x][y] == 'S') z = movs = dfs(x+1,y,movs);
    else if(mat[x][y] == 'E') z = dfs(x,y+1,movs);
    else if(mat[x][y] == 'W') z = dfs(x,y-1, movs);

    if(flag) ans[x][y] = z;
    else if(!flag) ans[x][y] = z+1;
    if(flag and x == caldax and y == calday) flag = false;

    tot += ans[x][y];
    return ans[x][y];
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(!vis[i][j]) v++, dfs(i,j,0);
        }

    cout << tot << endl;

    return 0;
}

