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
char mat[T][T];
bool vis[T];
bool tmp[T];
int n,m;

int col(int j) {
    bool rep = 0;
    bool ord = 1;

    for(int i = 1; i < n; i++) {
        if(vis[i-1]) continue;
        rep |= (mat[i][j] == mat[i-1][j]);
        ord &= (mat[i][j] >= mat[i-1][j]);
        if(ord and mat[i][j] != mat[i-1][j]) tmp[i-1] = 1;
    }

    if(!ord) return 2;
    return rep;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];

    int ans = 0;

    for(int j = 0; j < m; j++) {
        memset(tmp, 0, sizeof tmp);
        int x = col(j);
        if(x == 0) break;
        else if(x == 2) ans ++;
        else for(int i = 0; i < n; i++) vis[i] |= tmp[i]; 
    }

    cout << ans << endl;

    return 0;
}

