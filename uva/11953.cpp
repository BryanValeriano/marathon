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

const int T = 105; 
char mat[T][T];
bool vis[T][T];

int n;

int mov[4][2] = { {1,0},  {0,1}, {-1,0}, {0,-1} };

bool isIn(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < n);
}

void dfs(int i, int j) {
    vis[i][j] = true;
    for(int k = 0; k < 4; k++) {
        int ii = i + mov[k][0];
        int jj = j + mov[k][1];
        if(isIn(ii,jj) and !vis[ii][jj] and (mat[ii][jj] == 'x' or mat[ii][jj] == '@'))
            dfs(ii,jj);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        cin >> n;
        int ans = 0;
        memset(vis, 0 , sizeof vis);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> mat[i][j];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(!vis[i][j] and mat[i][j] == 'x') ans++, dfs(i,j);

        cout << "Case " << ++cont << ": " << ans << endl;
    }
    return 0;
}

