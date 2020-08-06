#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 1e5 + 5;
int pai[TAM];
int peso[TAM];
ll qtd[TAM];

int find(int x) {
    if(pai[x] == x) return x;
    else return pai[x] = find(pai[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(peso[x] > peso[y]) {
        pai[y] = x;
        qtd[x] += qtd[y];
    }
    else if(peso[x] < peso[y]) {
        pai[x] = y;
        qtd[y] += qtd[x];
    } else {
        pai[y] = x;
        qtd[x] += qtd[y];
        peso[x]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    int m; 
    cin >> n >> m;
    while(n or m) {
        for(int i = 1; i <= n; i++) pai[i] = i;
        for(int i = 1; i <= n; i++) cin >> qtd[i];
        memset(peso, 1, sizeof peso);
        
        int op, a, b;
        int cont = 0;
        while(m--) {
            cin >> op >> a >> b;
            if(op == 1) join(a, b);
            else {
                a = find(a);
                b = find(b);
                find(1);
                if(qtd[a] > qtd[b] && pai[1] == a) cont++;	
                else if(qtd[a] < qtd[b] && pai[1] == b) cont++;	
            }
        }
        cout << cont << endl;
        cin >> n >> m;
    }

    return 0;
}

