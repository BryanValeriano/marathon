#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)   cout << #x << " = " << x << endl
#define ok      cout << "ok" << endl
#define endl '\n'
 
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int n, m;
 
struct node {
    int u,v,c;
 
    bool operator < (const node &b) {
        return c < b.c;
    }
};
 
vector<node> g;
unordered_map<string , int> ind;
 
const int T = 2e3 + 5;
int pai[T];
int peso[T];
 
void init() {
    for(int i = 0; i < T; i++) pai[i] = i, peso[i] = 1;
}
 
int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}
 
void join(int x, int y) {
    x = find(x);
    y = find(y);
   
    if(peso[y] > peso[x]) swap(x,y);
 
    pai[y] = x;
    peso[x] += peso[y];
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    string u,v;
    int c;
    while(tc--) {
        init();
        g.clear();
        ind.clear();
        cin >> n >> m;
        int cont = 0;
 
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> c;
            if(!ind.count(u)) ind[u] = cont++;
            if(!ind.count(v)) ind[v] = cont++;
            g.pb({ind[u],ind[v],c});
        }
 
        sort(g.begin(), g.end());
        int ans = 0;
 
        for(int i = 0; i < m; i++) {
            if(find(g[i].u) != find(g[i].v)) {
                join(g[i].u, g[i].v);
                ans += g[i].c;
            }
        }
 
        cout << ans << endl;
        if(tc) cout << endl;
    }
   
    return 0;
}
