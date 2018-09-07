#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef pair<int, int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 103;
int m[N][N];
int dist[N][N]; 
bool visit[N][N]; 
int n;

struct node {
    int dist;
    int x;
    int y;
};

typedef bool (*comp)(node,node);
bool compare(node a, node b) {
    return a.dist > b.dist;
}

node cria(int dist, int x, int y){
    node tmp;
    tmp.dist = dist;
    tmp.x = x;
    tmp.y = y;
    return tmp;
}

void solve(int lin, int col) {
    memset(dist, INF, sizeof dist);
    dist[lin][col] = 0;
    priority_queue<node, vector<node>, comp > fila(compare);
    fila.push(cria(0,0,0));
    
    while(true) {
        node davez = cria(-1, -1, -1);

        while(!fila.empty()){
            node aux = fila.top();
            fila.pop();
            if(!visit[aux.x][aux.y]) {
                davez = aux;
                break;
            }
        }
        if(davez.x == -1) break;
        
        int x = davez.x, y = davez.y;
        visit[x][y] = true;

        if(x-1>=0) {
            if(dist[x-1][y] > m[x-1][y]+dist[x][y]) {
                dist[x-1][y] = m[x-1][y]+dist[x][y];
                fila.push(cria(dist[x-1][y], x-1, y));
            }
        }

        if(y-1>=0) {
            if(dist[x][y-1] > m[x][y-1]+dist[x][y]) {
                dist[x][y-1] = m[x][y-1]+dist[x][y];
                fila.push(cria(dist[x][y-1], x, y-1));
            }
        }

        if(x+1<n) {
            if(dist[x+1][y] > m[x+1][y]+dist[x][y]) {
                dist[x+1][y] = m[x+1][y]+dist[x][y];
                fila.push(cria(dist[x+1][y], x+1, y));
            }
        }

        if(y+1<n) {
            if(dist[x][y+1] > m[x][y+1]+dist[x][y]) {
                dist[x][y+1] = m[x][y+1]+dist[x][y];
                fila.push(cria(dist[x][y+1], x, y+1));
            }
        }
    }
}

int main() {

    cin >>n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> m[i][j];
        }
    }
    
    solve(0,0);
    cout <<dist[n-1][n-1] <<endl;
    return 0;
}

