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
int cont = 2;
int n,m;
int g[T][T];
int memo[T*T];

int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

bool in(int a, int b) {
    return (a >= 1 and a <= n and b >= 1 and b <= m);
}

int dfs(int a, int b) {
    if(g[a][b] == 0) return 1; 
    if(g[a][b] == cont) return 0;
    g[a][b] = cont;
    int ans = 0;
    for(int k = 0; k < 4; k++) {
        int aa = a + mov[k][0];
        int bb = b + mov[k][1];
        if(in(aa,bb)) ans += dfs(aa,bb);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int k, a, b;
    char aux;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            cin >> aux;
            if(aux == '.') g[i][j] = 1;
            else g[i][j] = 0;
        }
    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        if(g[a][b] != 1) cout << memo[g[a][b]] << endl;
        else { 
            int ans = dfs(a,b);
            memo[cont] = ans;
            cont++;
            cout << ans << endl;
        }
    }
    return 0;
}

