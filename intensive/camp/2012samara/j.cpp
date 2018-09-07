#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
typedef pair<int,int> pii;
const  ll INF = 0x3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int N = 1e3+3;
const int M = 2e3+3;
int teto = 1e6+3;
int n, m;
ll dist[N];
int visit[N];

struct node {
    int prox;
    int t;
    int s;
};

vector<node> graph[N];

node constroi(int a, int b, int c) {
    node tmp;
    tmp.prox = a;
    tmp.t = b;
    tmp.s = c;
    return tmp;
}

ll dij(int maxseg, int atual) {
    memset(dist, inf, sizeof dist); 
    memset(visit, 0, sizeof visit); 
    dist[atual] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > fila;
    fila.push(mk(dist[atual], atual));

    while(true) {
        int davez = -1;
        while(!fila.empty()) {
            pii tmp = fila.top();
            fila.pop();
            if(!visit[tmp.second]) { 
                davez = tmp.second;
                break;
            }
        }
        if(davez == -1) break;
        visit[davez] = 1;
        for(int i = 0; i < graph[davez].size(); i++) {
            int ind = graph[davez][i].prox;
            node vizinho = graph[davez][i];
            if(dist[ind] > dist[davez] + vizinho.t && maxseg >= vizinho.s) {
                dist[ind] = dist[davez] + vizinho.t;
                fila.push(mk(dist[ind], ind));
            }
        }
    }
    return dist[n];
}

 
int main()
{
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    cin >> n >> m;
    int x, y, t, s;
    for(int j = 0; j < m; j++) {
        cin >> x >> y >> t >> s; 
        node tmp = constroi(y,t,s);
        graph[x].pb(tmp);
        tmp = constroi(x,t,s);
        graph[y].pb(tmp);
    }
    int lim; cin >> lim;
    int ini = 0;
    int fim = teto;
    ll resp = INF;
    ll seg = 0;
    while(ini <= fim) {
        int meio = (ini + fim) >> 1;
        ll aux = dij(meio, 1);
        if(aux <= lim) { fim = meio - 1; resp = aux; seg = meio; }
        else ini = meio + 1;
    }
    
    (resp < inf)? (cout << "YES" << endl << seg << " " << resp) : (cout << "NO");
    cout << endl; 
    return 0;
}

