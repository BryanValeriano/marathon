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

char mat[200][200];
int dist[200][200];
int n,m;

struct node {
    int i,j,c;
};

queue<node> lista;

int mov[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };

bool isIn(int x, int y) {
    return (x >= 0 and x < n and y >= 0 and y < m);
}

void bfs() {
    while(!lista.empty()) {
        node at = lista.front();
        lista.pop();

        for(int k = 0; k < 4; k++) {
            int ii = at.i + mov[k][0];
            int jj = at.j + mov[k][1];
            if(isIn(ii,jj) and at.c+1 < dist[ii][jj]) {
                dist[ii][jj] = at.c+1;
                lista.push({ii,jj,at.c+1});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    string s;
    while(tc--) {
        cin >> n >> m;
        memset(dist, INF, sizeof dist);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> mat[i][j];
                if(mat[i][j] == '1') {
                    lista.push({i,j,0});
                    dist[i][j] = 0;
                }
            }
        }

        bfs();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                cout << dist[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}

