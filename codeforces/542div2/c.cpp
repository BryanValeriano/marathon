#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<ll,ll> > vii;
const ll INF = 0x3f3f3f3f3f3f3f;

const int T = 52;

int n;
char mat[T][T];
bool vis[T][T];
int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
vii v[2];

bool isIn(int x, int y) {
    return (x >= 1 and x <= n and y >= 1 and y <= n);
}

void dfs(int i, int j, int op) {
    vis[i][j] = 1;
    v[op].eb(i,j);

    for(int k = 0; k < 4; k++) {
        int ii = i + mov[k][0];
        int jj = j + mov[k][1];
        if(isIn(ii,jj) and !vis[ii][jj] and mat[ii][jj] == '0') dfs(ii,jj,op);
    }
}
    


int main() {
    ios::sync_with_stdio(false);
    int r1,c1,r2,c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> mat[i][j];

    dfs(r1,c1,0);
    dfs(r2,c2,1);

    if(v[0].size() == 0 or v[1].size() == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = INF;

    for(int i = 0; i < v[0].size(); i++)
        for(int j = 0; j < v[1].size(); j++) 
            ans = min(ans, (v[0][i].fi - v[1][j].fi) * (v[0][i].fi - v[1][j].fi) + (v[0][i].se - v[1][j].se) * (v[0][i].se - v[1][j].se));

    cout << ans << endl;

    return 0;
}

