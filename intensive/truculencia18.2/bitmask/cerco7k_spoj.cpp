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
const int T = 103;
const int N = 20;
int v[T][T];
char mat[T][T];
int n, m;
int startx, starty;
int dp[T][T][N];

// vazio = 0
// r = 1
// b = 2
// g = 3
// y = 4

int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

struct node { int x,y,mask,passos; };

bool isIn(int x, int y) {
    return (x >= 0 and x < n and y >= 0 and y < m and v[x][y] != 16);
}

bool isGol(char x) {
    return (x == 'X');
}

bool isDoor(char x) {
    return (x >= 'A' and x <= 'Z');
}

bool isKey(char x) {
    return (x >= 'a' and x <= 'z');
}

int bfs() {
    queue<node> list;
    list.push({startx,starty,0,0});
    while(!list.empty()) {
        node atual = list.front();
        list.pop();
        for(int k = 0; k < 4; k++) {
            int xx = atual.x + mov[k][0];
            int yy = atual.y + mov[k][1];
            if(isIn(xx,yy)) {

                node tmp = atual;
                tmp.x = xx; tmp.y = yy;
                tmp.passos++;
                int &r = dp[xx][yy][tmp.mask];

                if(isGol(mat[xx][yy])) return tmp.passos;
                else if(isKey(mat[xx][yy])) {
                    tmp.mask |= v[xx][yy];
                    int &r = dp[xx][yy][tmp.mask];
                    if(tmp.passos < r) {
                        list.push(tmp);
                        r = tmp.passos;
                    }
                }
                else if(isDoor(mat[xx][yy])) {
                    if(atual.mask & v[xx][yy]) {
                        if(tmp.passos < r) {
                            r = tmp.passos;
                            list.push(tmp);
                        }
                    }
                } else if(tmp.passos < r) {
                    list.push(tmp);
                    r = tmp.passos;
                }
            }
        }
    }
    return -1;
}

int transform(char x) {
    if(x == '.' or x == '*' or x == 'X') return 0;
    if(x == 'R' or x == 'r') return 1;
    if(x == 'B' or x == 'b') return 2;
    if(x == 'G' or x == 'g') return 4;
    if(x == 'Y' or x == 'y') return 8;
    if(x == '#') return 16;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    while(n or m) {
        char aux;
        memset(dp, INF, sizeof dp);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                cin >> mat[i][j];
                v[i][j] = transform(mat[i][j]);
                if(mat[i][j] == '*') { startx = i; starty = j; }
            }
        int ans = bfs();
        if(ans == -1) cout << "The poor student is trapped!" << endl;
        else cout << "Escape possible in " << ans << " steps." << endl;
        cin >> n >> m;
    }
    return 0;
}

