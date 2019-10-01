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

const int T = 2e5 + 3;
bool v[2][T];
int vis[2][T][2];
bool dp[2][T][2];
int n,vez;
string s1,s2;

bool dfs(int x, int y, bool mov) {
    if(y == n) return 0;
    if(x == 1 and y == (n-1)) return (v[x][y] == mov);

    if(vis[x][y][mov] == vez) return dp[x][y][mov];
    vis[x][y][mov]= vez;
    bool ok = 0;

    if(v[x][y] == 0) {
        if(mov) ok |= dfs(!x,y,0);
        else ok |= dfs(x,y+1,1);
    } else if(mov) ok |= dfs(x,y+1,1);

    return dp[x][y][mov] = ok;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        cin >> s1 >> s2;
        for(int i = 0; i < n; i++) v[0][i] = (s1[i] <= '2');
        for(int i = 0; i < n; i++) v[1][i] = (s2[i] <= '2');
        vez++;
        cout << (dfs(0,0,1)? "YES" : "NO") << endl;
    }
    return 0;
}

