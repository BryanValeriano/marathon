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

bool vis[T];
int st[T];
int d[T];
int low[T];
int comp[T];
int t,sz;
vector<int> adj[T];

void dfs(int u) {
    vis[u] = 1;
    st[sz++] = u;
    d[u] = low[u] = t++;

    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], d[v]);
    }
        
    if(low[u] >= d[u]) {    
        int a;
        do {
            a = st[--sz];
            comp[a] = u;
            d[a] = INF;
        } while(a != u);
    }
}

int main() {
    ios::sync_with_stdio(false);

    return 0;
}

