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
const int T = 1e5 + 10;
int n, m, q;
bool ehQuery[T];
int ans[T];
int pai[T];
int peso[T];
vii arestas(T);
vector<int> querys(T);

void init() {
    for(int i = 0; i < T; i++) {
        pai[i] = i;
        peso[i] = 0;
    }
}

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    if(peso[x] == peso[y]) peso[x]++;
}

int main() {
    ios::sync_with_stdio(false);
    init();
    cin >> n >> m;
    int a, b;
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        arestas[i] = mk(a,b);
    }
    cin >> q;
    for(int i = 1; i <= q; i++) {
        cin >> a;
        ehQuery[a] = true;
        querys[i] = a;
    }

    int comps = n;

    for(int i = 1; i <= m; i++) {
        if(!ehQuery[i] and find(arestas[i].fi) != find(arestas[i].se)) {
            join(arestas[i].fi, arestas[i].se);
            comps--;
        }
    }

    for(int i = q; i >= 1; i--) {
        ans[i] = comps;
        if(find(arestas[querys[i]].fi) != find(arestas[querys[i]].se)) {
            join(arestas[querys[i]].fi, arestas[querys[i]].se);
            comps--;
        }
    }

    for(int i = 1; i < q; i++) cout << ans[i] << " ";
    cout << ans[q] << endl;

    return 0;
}

