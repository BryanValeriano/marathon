#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 1e3+2;
vector< pair<int, ll> >graph[TAM];
bool visitados[TAM];

void dfs(int ini, int fim, ll tempo) {
    visitados[ini] = true;
    if(ini == fim) return;

    for(int i = 0; i < graph[ini].size(); i++) {
        pair<int, ll>vizinho = graph[ini][i];
        if(!visitados[vizinho.fi] && vizinho.sec <= tempo)
            dfs(vizinho.fi, fim, tempo);            
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int m; cin >> m;

    for(int i = 0; i < m; i++) {
        int tmp1, tmp2;
        ll peso;
        cin >> tmp1 >> tmp2 >> peso;
        graph[tmp1].pb(mk(tmp2, peso));
        graph[tmp2].pb(mk(tmp1, peso));
    }

    ll ini = 0;
    ll fim = 1e9+3;
    ll meio;

    while(ini <= fim) {
        memset(visitados, 0, sizeof visitados);
        meio = (ini + fim) >> 1;
        dfs(0, n-1, meio);
        if(visitados[n-1])fim = meio - 1;
        else ini = meio + 1;
    }

    cout << ini << endl;
    return 0;
}
