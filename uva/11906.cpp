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

const int T = 102;

int n,m,a,b,w,v;
bool mat[T][T];
int vis[T][T];
vector<vector<int> > bag;
set<ii> mov;

bool isIn(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m);
}

ii dfs(int i, int j) {
    vis[i][j] = v;
    ii ans = mk(1,0);
    int x = 0;

    for(auto k : mov) {
        int i2 = i + k.fi;
        int j2 = j + k.se;
        if(isIn(i2,j2) and !mat[i2][j2]) {
            x++;
            if(vis[i2][j2] != v) {
                ii f = dfs(i2,j2);
                ans.fi += f.fi;
                ans.se += f.se;
            }
        }
    }

    if(x&1) ans.se++;
    return ans;
}




int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        cin >> n >> m >> a >> b >> w;

        mov.clear();
        bag = { {a,b}, {-a,b}, {a,-b}, {-a,-b}, {b,a}, {-b,a}, {b,-a}, {-b,-a} };
        for(int i = 0; i < 8; i++) mov.insert(mk(bag[i][0],bag[i][1]));

        memset(mat,0,sizeof mat);
        for(int i = 0; i < w; i++) {
            int x,y;
            cin >> x >> y;
            mat[x][y] = 1;
        }
        v++;
        ii ans = dfs(0,0);
        cout << "Case " << ++cont << ": " << ans.fi-ans.se << " " << ans.se << endl;
    }

    return 0;
}

