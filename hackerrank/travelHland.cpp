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

struct arestaQuery {
    int u, v, cust;
    
    arestaQuery(int u, int v, int cust) :
        u(u), v(v), cust(cust) {}

    bool operator < (const arestaQuery &b) const {
        if(cust != b.cust) return cust < b.cust;
        return false;
    }
};

const int T = 1e5 + 3;
ll predio[T];
vector <arestaQuery> arestas;
vector <arestaQuery> query;
int n, m, q;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    arestas.reserve(T);
    query.reserve(T);
    for(int i = 1; i <= n; i++)
        cin >> predio[i];
    int u, v, c;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        arestas.eb(u,v,c);
    } 
    for(int i = 0; i < q; i++) {
        cin >> u >> v >> c;
        arestas.eb(u,v,c);
    }
    sort(arestas.begin(), arestas.end());
    sort(query.begin(), query.end());

    int lastA = 0;
    for(int i = 0; i < q; i++) {
        while(arestas[lastA].cust < query[i].cust && lastA < n) { 
            join(arestas[lastA].u, arestas[lastA].v); 
            lastA++;
        }
        if(find(query.u) 
        
     

    return 0;
}

