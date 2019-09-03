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
const int T = 25;
int n,m;
bool vis[T][T];
char g[T][T];
char gol;

int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

bool in(int x, int y) {
    return (x >= 0 and x < m and y >= 0 and y < n);
}

int dfs(int x, int y) {
    vis[x][y] = true;
    int ans = 0;
    for(int k = 0; k < 4; k++) { 
        int xx = x + mov[k][0];
        int yy = y + mov[k][1];
        if(yy == n) yy = 0;
        if(yy == -1) yy = n-1;
        if(in(xx,yy) and !vis[xx][yy] and g[xx][yy] == gol) 
            ans += dfs(xx,yy) + 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    while(cin >> m) {
        int ans = 0;
        cin >> n;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> g[i][j];
        int a, b; 
        cin >> a >> b;
        gol = g[a][b];
        memset(vis, 0, sizeof vis);
        dfs(a,b);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) 
                if(g[i][j] == gol and !vis[i][j]) 
                    ans = max(ans, dfs(i,j)+1);
        cout << ans << endl;
    }
    return 0;
}

