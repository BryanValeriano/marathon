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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1002;
char g[T][T];
bool vis[T][T];
int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0-1} };
int mov2[3][2] = { {0,1}, {1,0}, {1,1} };
int mov3[4][2] = { {1,1}, {1,-1}, {-1,-1}, {-1,1} };
int n,m;

bool isIn(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m);
}

bool dfs(int i, int j) {
    vis[i][j] = 1;
    bool ans = 1;
    for(int k = 0; k < 4; k++) {
        int ii = i+mov[k][0];
        int jj = j+mov[k][1];
        if(isIn(ii,jj) and !vis[ii][jj] and g[ii][jj] == '.') ans &= dfs(ii,jj);
        if(!isIn(ii,jj)) ans = 0;
    }
    return ans;
}

bool diamond(int i, int j) {
    bool ok = 1;
    for(int k = 0; k < 3; k++) {
        int ii = i+mov2[k][0];
        int jj = j+mov2[k][1];
        ok &= (isIn(ii,jj) and g[ii][jj] == (k<=1? '\\' : '/' ));
    }
    if(ok) cout << "diamond\n";
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> g[i][j];

    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(vis[i][j]) continue;
            else if(g[i][j] == '.') ans += dfs(i,j);
            else if(g[i][j] == '/') ans += diamond(i,j);
        }
    cout << ans << endl;
    return 0;
}

