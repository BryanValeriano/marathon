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

bool dfs(int ini, int fim, ll tempo) {
    if(visitados[ini]) return false;
    if(ini == fim) return true;

    for(int i = 0; i < graph[ini].size(); i++) {
        pair<int, ll>vizinho = graph[ini][i];
        if(vizinho.sec <= tempo) {
            visitados[ini] = true;
            bool sinal = dfs(vizinho.fi, fim, tempo);            
            if(sinal) return true;
        }
    }
    return false;
}

int main() {
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
        if(dfs(0, n-1, meio)) fim = meio - 1;
        else ini = meio + 1;
    }

    cout << ini << endl;
    return 0;
}
