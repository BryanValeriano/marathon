#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 102;
char g[T][T];
bool vis[T][T];
int mov[8][2] = { {2,1}, {-2,1}, {2,-1}, {-2,-1}, {1,2}, {-1,2}, {1,-2}, {-1,-2} };
int n;

bool isIn(int x, int y) {
    return (x >= 0 and x < n and y >= 0 and y < n);
}

void bfs(int i, int j) {
    queue<pair<ii,int>> lista;
    lista.emplace(mk(i,j),0);
    vis[i][j] = 1;

    while(!lista.empty()) {
        pair<ii,int> tmp = lista.front();
        ii at = tmp.fi;
        int cor = tmp.se;
        g[at.fi][at.se] = (cor? 'W' : 'B');
        lista.pop();

        for(int k = 0; k < 8; k++) {
            int ii = at.fi + mov[k][0];
            int jj = at.se + mov[k][1];
            if(isIn(ii,jj) and !vis[ii][jj]) {
                vis[ii][jj] = 1;
                lista.emplace(mk(ii,jj),!cor);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(!vis[i][j])
                bfs(i,j);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << g[i][j];
        cout << endl;
    }

    return 0;
}

