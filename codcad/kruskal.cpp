#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 130000;  

int peso[510];
int pai[510];

struct aresta {
    int x;
    int y;
    int dist;
};

aresta grafo[TAM];

bool cmp(aresta a, aresta b) {
    return a.dist < b.dist;
}

int find(int x) {
    if(pai[x] == x) return x;
    else return pai[x] = find(pai[x]);
}

void join(int a, int b) {
    a = find(a);
    b = find(b);

    if(peso[a] > peso[b]) pai[b] = a;
    else if(peso[a] < peso[b]) pai[a] = b;
    else {
        pai[b] = a;
        peso[a]++;
    }
}
 
int main()
{
    int n; cin >> n;
    int m; cin >> m;
    for(int i = 1; i <= n; i++) pai[i] = i;
    for(int i = 1; i <= n; i++) peso[i] = 1;
    for(int i = 1; i <= m; i++) 
        cin >> grafo[i].x >> grafo[i].y >> grafo[i].dist;
   
    sort(grafo + 1, grafo + m+1, cmp);   

    int qtd = 0;
    for(int i = 1; i <= m; i++) {
        if(find(grafo[i].x) != find(grafo[i].y)) {
            join(grafo[i].x, grafo[i].y); 
            qtd += grafo[i].dist; 
        }
    }
    cout << qtd << endl;
    return 0;
}

