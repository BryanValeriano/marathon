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
vector<int> g[T];
int tmp[T];
int cor[T];
int tin[T];
int tout[T];
int seg[4*T];
int lazy[4*T];
bool viz[T];
int n, t, a, b;

void prop(int node, int i, int j) {
    if(lazy[node] == 0) return;
    seg[node] = (j-i+1) - seg[node];
    if(i != j) {
        if(lazy[2*node] == 0) lazy[2*node] = 1; 
        else lazy[2*node] = 0;
        if(lazy[2*node+1] == 0) lazy[2*node+1] = 1;
        else lazy[2*node+1] = 0;
    }
    lazy[node] = 0;
}

void update(int node, int i, int j) {
    prop(node, i, j);
    if(i > b or j < a) return; 
    if(i >= a and j <= b) {
        if(lazy[node] == 0) lazy[node] = 1;
        else lazy[node] = 0;
        prop(node, i, j);
        return;
    }
    int mid = (i + j) >> 1;
    update(2*node, i, mid);
    update(2*node+1, mid+1, j);
    seg[node] = seg[2*node] + seg[2*node+1];
}

int query(int node, int i, int j) {
    prop(node, i, j);
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i + j) >> 1;
    return query(2*node, i, mid) + query(2*node+1, mid+1, j);
}

void query() {
    int q, node;
    string oper;
    cin >> q;
    while(q--) {
        cin >> oper >> node;
        a = tin[node];
        b = tout[node];
        if(oper == "get") cout << query(1,1,n) << endl;
        else update(1,1,n);
    }
}

void build(int node, int i, int j) {
    if(i == j) seg[node] = cor[i];
    else {
        int mid = (i+j) >> 1;
        build(2*node, i, mid);
        build(2*node+1, mid+1,j);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

void dfs(int atual) {
    tin[atual] = ++t;
    cor[t] = tmp[atual];
    for(int i = 0; i < g[atual].size(); i++) {
        int vizinho = g[atual][i];
        if(!viz[vizinho]) 
            viz[vizinho] = true;
            dfs(vizinho);
    }
    tout[atual] = t;
}

void build() {
    dfs(1);
    build(1, 1, n); 
}

void read() {
    cin >> n;
    int aux;
    for(int i = 2; i <= n; i++) {
        cin >> aux;
        g[aux].pb(i);
    }
    for(int i = 1; i <= n; i++)
        cin >> tmp[i];
}

int main() {
    ios::sync_with_stdio(false);
    read();
    build();
    query();
    return 0;
}

