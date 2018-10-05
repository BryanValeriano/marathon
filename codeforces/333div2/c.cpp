#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f;
const int TAM = 400 + 5;
int nodes; int arestas;    
int G[TAM][TAM];
int dist[TAM];
int proc[TAM];

int dij(int origem, int destino, int flag) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    memset(dist, INF, sizeof dist);
    dist[origem] = 0;
    pq.emplace(dist[origem], origem);
    while(true) {
        pii davez = mp(-1,-1);
        while(!pq.empty()) {
            pii atual = pq.top();
            pq.pop();
            if(!proc[atual.se]) {
                davez = atual;
                break;
            }
        }
        if(davez.fi == -1) break;
        if(davez.se == destino) return davez.fi;
        int atual = davez.se;
        proc[atual] = 1;
        int dis = dist[atual];
        for(int i = 1; i <= nodes; i++) {
            if(G[atual][i] == flag) {
                if(dis + 1 < dist[i]) {
                    dist[i] = dis + 1;
                    pq.emplace(dist[i], i);
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> nodes >> arestas;
    int u, v;
    for(int i = 0; i < arestas; i++) {
        cin >> u >> v; 
        G[u][v] = 1;
        G[v][u] = 1;
    }
    int flag = 0;
    if(G[1][nodes] == 0) flag = 1;
    cout << dij(1, nodes, flag) << endl; 
    return 0;
}

