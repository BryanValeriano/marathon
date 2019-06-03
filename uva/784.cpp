#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)   cout << #x << " = " << x << endl
#define ok      cout << "ok" << endl
#define endl '\n'
 
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
string mat[35];
int n,m;
int vis[35][85];
int v;
 
int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
 
bool isIn(int x, int y) {
    return (x >= 0 and x < n and y >= 0 and y < m);
}
 
void bfs(int x, int y) {
    v++;
    queue<ii> fila;
    fila.emplace(x,y);
    vis[x][y] = v;
    while(!fila.empty()) {
        ii at = fila.front();
        fila.pop();
        mat[at.fi][at.se] = '#';
        for(int k = 0; k < 4; k++) {
            int xx = mov[k][0] + at.fi;
            int yy = mov[k][1] + at.se;
            if(isIn(xx,yy) and mat[xx][yy] == ' ' and vis[xx][yy] != v) {
                vis[xx][yy] = v;
                fila.emplace(xx,yy);
            }
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    string x;
    getline(cin,x);
    while(tc--) {
        n = 0;
        while(1) {
            getline(cin,x);
            if(x[0] == '_') break;
            mat[n++] = x;
        }
        m = mat[0].size();
 
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(mat[i][j] == '*') bfs(i,j);
 
        for(int i = 0; i < n; i++)
            cout << mat[i] << endl;
        cout << x << endl;
    }
    return 0;
}
