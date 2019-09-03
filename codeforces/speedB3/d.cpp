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

const int T = 502;
char mat[T][T];
bool vis[T][T];
int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

int n,m,s,qtd,tot;

bool isIn(int x, int y) {
    return (x >= 0 and x < n and y >= 0 and y < m);
}

void dfs(int i, int j) {
    if(qtd == (tot - s)) return;
    vis[i][j] = 1;
    qtd++;

    for(int k = 0; k < 4; k++) { 
        int ii = i + mov[k][0];
        int jj = j + mov[k][1];
        if(isIn(ii,jj) and !vis[ii][jj] and mat[ii][jj] == '.') dfs(ii,jj);
    }
}

void solve() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j] == '.') { dfs(i,j); return; }
}

void read() {
    cin >> n >> m >> s;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == '.') tot++;
        }
}

void print() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == '.' and !vis[i][j]) cout << 'X';
            else cout << mat[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    read();
    solve();
    print();
    return 0;
}

