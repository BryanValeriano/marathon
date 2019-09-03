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

const int T = 505;
char g[T][T];
bool vis[T][T];
int n, m;

bool isIn(int x, int y) {
    return(x-1 >= 0 and x+1 < n and y-1 >= 0 and y+1 < m);
}

bool has(int x, int y) {
    return (g[x][y] == g[x-1][y] and g[x][y] == g[x+1][y] and g[x][y] == g[x][y-1] and g[x][y] == g[x][y+1] and g[x][y] == '*'); 
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    int sobe = 1;

    while(x+sobe < n and g[x+sobe][y] == '*') vis[x+sobe++][y] = 1;
    sobe = 1;
    while(x-sobe >= 0 and g[x-sobe][y] == '*') vis[x-sobe++][y] = 1;

    sobe = 1;
    while(y+sobe < m and g[x][y+sobe] == '*') vis[x][y+sobe++] = 1;
    sobe = 1;
    while(y-sobe >= 0 and g[x][y-sobe] == '*') vis[x][y-sobe++] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    bool flag = 0;

    for(int i = 0; i < n; i++) cin >> g[i];

    for(int i = 0; i < n and !flag; i++) 
        for(int j = 0; j < m and !flag; j++) 
            if(isIn(i,j) and has(i,j)) { 
                flag = 1;
                dfs(i,j);
            }

    if(!flag) { cout << "NO" << endl; return 0; }

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            if(!vis[i][j] and g[i][j] == '*') { cout << "NO" << endl; return 0; }

    cout << "YES" << endl;
    return 0;
}

