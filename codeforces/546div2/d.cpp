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
const int T = 3e5 + 10;

int id[T];
int que[T];
int pai[T];
ll peso[T];
set<int> g[T];

void init() {
    for(int i = 1; i < T; i++) pai[i] = i, peso[i] = 1;
}

int find(int x) {
    return (pai[x] == x? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
}

int main() {
    ios::sync_with_stdio(false);
    int n, q, x, y; cin >> n >> q;
    init();

    for(int i = 1; i <= n; i++) {
        cin >> x;
        id[x] = i;
        que[i] = x;
    }

    for(int i = 0; i < q; i++) {
        cin >> x >> y;
        g[x].insert(y);
        //g[y].insert(x);
    }

    for(int i = 1; i < n; i++) 
        if(g[que[i]].count(que[i+1])) 
            join(que[i], que[i+1]);

    
    for(int i = 1; i < n; i++) 
        for(int x : g[que[id[i]]]) {
            int tras = find(que[id[i]]-1);
            int frente = find(que[id[i]]+1);
            int viztras = find(id[x]-1);
            int vizfrente = find(id[x]+1);
            int viz = find(id[x]);
            if(frente == viz or frente == viztras or frente == vizfrente
                    or tras == viz or tras == viztras or tras == vizfrente) join(i,x);
        }


    int ele = find(que[n]);
    cout << ele << endl;
    int mini = n;

    for(int i = 1; i <= n; i++) {
        if(find(i) == ele) mini = min(mini, id[i]);
        cout << i << " " << id[i] << " " << find(i) << endl; 
    }
    cout << mini << endl;
    cout << n-mini+1 << endl;
    
    return 0;
}
