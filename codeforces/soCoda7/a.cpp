#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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
const int T = 2e3 + 3;

int n,m;
char mat[T][T];
bool vis[T][T];
queue<ii> fila;

//                      down right                down left                     up right
int mov[4][3][2] = { { {1,0}, {1,1}, {0,1} }, { {1,0}, {1,-1}, {0,-1} }, { {-1,0}, {-1,1}, {0, 1} },
                     { {-1,0}, {-1,-1}, {0,-1} } };

bool isIn(int x, int y) {
    return (x >= 0 and y >= 0 and x < n and y < m);
}

bool only(int x, int y) {

    for(int p = 0; p < 4; p++) {
        int qtd = 0;
        for(int k = 0; k < 3; k++) {
            int xx = x + mov[p][k][0];
            int yy = y + mov[p][k][1];
            if(isIn(xx,yy) and mat[xx][yy] == '.') qtd++;
        }
        if(qtd == 3) return 1;
    }

    return 0;
}

void bfs() {
    while(!fila.empty()) {
        ii at = fila.front();
        fila.pop();

        for(int p = 0; p < 4; p++) {
            for(int k = 0; k < 3; k++) {
                int xx = at.fi + mov[p][k][0];
                int yy = at.se + mov[p][k][1];
                if(isIn(xx,yy) and mat[xx][yy] == '*' and !vis[xx][yy] and only(xx,yy)) {
                    vis[xx][yy] = 1;
                    mat[xx][yy] = '.';
                    fila.emplace(xx,yy);
                }
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];


    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] == '*' and only(i,j)) {
                mat[i][j] = '.';
                vis[i][j] = 1;
                fila.emplace(i,j);
            }

    bfs();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << mat[i][j];
        cout << endl;
    }

    return 0;
}

