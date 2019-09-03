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

const int T = 2e5 + 10;
int pai[T];
int peso[T];
int v[T];
bool vis[T];
vector<int> equals[T];

void init() {
    for(int i = 1; i < T; i++) {
        pai[i] = i;
        peso[i] = 1;
        equals[i].pb(i);
    }
}

int find(int x) {
    return pai[x] == x? x : pai[x] = find(pai[x]);
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return;
    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];

    for(auto z : equals[y]) equals[x].pb(z);
}

int main() {
    ios::sync_with_stdio(false);

    init();
    int n,m,k; cin >> n >> m >> k;
    int u,x;

    for(int i = 1; i <= n; i++) cin >> v[i];


    for(int i = 0; i < m; i++) {
        cin >> u >> x;
        join(u,x);
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        int at = find(i);
        if(!vis[at]) {
            vis[at] = 1;
            map<int,int> cor;
            int best = 0;

            for(int j = 0; j < equals[at].size(); j++) {
                cor[v[equals[at][j]]]++;
                if(cor[v[equals[at][j]]] > best) 
                    best = cor[v[equals[at][j]]];
            }

            ans += equals[at].size() - best; 

        }
    }

    cout << ans << endl;

    return 0;
}

