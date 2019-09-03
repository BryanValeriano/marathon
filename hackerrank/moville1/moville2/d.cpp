#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAXN  = 500;
//const int MAXM = 5e7;

struct t_aresta{
    int dis;
    int x, y;
};

bool comp(t_aresta a, t_aresta b){ return a.dis < b.dis; }

int n, m;
vector<t_aresta> aresta;
int pai[MAXN];
int peso[MAXN];

int find(int x){
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int a, int b){
    
    a = find(a);
    b = find(b);
    
    if(peso[a] < peso[b]) pai[a] = b;
    else if(peso[b] < peso[a]) pai[b] = a;
    else{
        pai[a] = b;
        peso[b]++;
    }
    
}


int main(){
    cin >> n >> m;
    
    int a; int b; int dist;
    for(int i = 1;i <= m;i++) {
        cin >> a >> b >> dist;
        t_aresta tmp;
        tmp.x = a; tmp.y = b; tmp.dis = dist;
        aresta.pb(tmp);
    }
    
   
    for(int i = 1;i <= n;i++) pai[i] = i;
    
    sort(aresta.begin(), aresta.end(), comp);
    
    int cust = 0;
    int size = 0;
        for(int i = 0;i < m;i++){
        
        if( find(aresta[i].x) != find(aresta[i].y) ){ 
            join(aresta[i].x, aresta[i].y);
            
            cust += aresta[i].dis;
        }
    }
    cout << cust << endl;
    
    return 0;
}
