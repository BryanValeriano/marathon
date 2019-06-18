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


const int T = 1005;

char mat[T][T];
int vis[T][T];
int flag[T][T];
int mov[8][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1} };
int n,m,v;

bool isIn(int x, int y) {
    return (x >= 0 and x < n and y >= 0 and y < m);
}

int bfs(int x, int y) {
    queue< pair<ii, int> > fila;       
    fila.emplace( mk(x,y), 0 ); 
    vis[x][y] = v;

    while(!fila.empty()) {
        pair<ii, int> tmp = fila.front();
        int i = tmp.fi.fi;
        int j = tmp.fi.se;
        int d = tmp.se;
        fila.pop();
        
        for(int k = 0; k < 8; k++) {
            int ii = i + mov[k][0];
            int jj = j + mov[k][1];

            while(isIn(ii,jj) and mat[ii][jj] != 'X') {
                if(vis[ii][jj] == v) {  
                    if(flag[ii][jj] & (1<<k)) break;
                    flag[ii][jj] |=  (1<<k);
                    ii += mov[k][0];
                    jj += mov[k][1];
                    continue;
                }
                if(mat[ii][jj] == 'F') return d+1; 
                vis[ii][jj] = v;
                flag[ii][jj] |=  (1<<k);
                fila.emplace(mk(ii,jj), d+1);
                ii += mov[k][0];
                jj += mov[k][1];
            }
        }
    }
    
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tc; cin >> tc;

    while(tc--) {
        cin >> n >> m;
        int inix = 0, iniy = 0;

        for(int i = 0; i < n; i++) {
            cin >> mat[i];
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 'S') inix = i, iniy = j;
            }
        }
        
        v++;
        memset(flag, 0, sizeof flag);
        cout << bfs(inix,iniy) << '\n';
    }

    return 0;
}

