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

const int T = 1010;
vector<int> g[T+T + 10];
int val[T + T + 10];
int in[T + T + 10];
int peso[T + T + 10];
int pai[T + T + 10];
char v[T][T];

void init() {
    for(int i = 0; i < T+T; i++) { 
        pai[i] = i;
        peso[i] = 1;
    }
}

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(peso[y] > peso[x]) swap(x,y);

    pai[y] = x;
    peso[x] += peso[y];
}


int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    init();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
            if(v[i][j] == '=') join(i, T+j);
        }
    }
            
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == '<') { g[find(i)].pb(find(T+j)); in[find(T+j)]++; }
            else if(v[i][j] == '>') { g[find(T+j)].pb(find(i)); in[find(i)]++; }
        }
    }

    queue<ii> list;
    set<int> entradas;

    for(int i = 0; i < n; i++) 
        if(in[find(i)] == 0) entradas.insert(find(i));
    for(int i = T; i < T+m; i++)
        if(in[find(i)] == 0) entradas.insert(find(i));

    for(auto x : entradas) list.emplace(x,1);

    while(!list.empty()) { 
        ii atual = list.front();
        list.pop();
        atual.fi = find(atual.fi);
        val[atual.fi] = atual.se;
        for(auto v : g[atual.fi]) {
            v = find(v);
            in[v]--;
            if(in[v] == 0) list.emplace(v,atual.se+1);
        }
    }

    
    vector<int> a;
    vector<int> b;

    for(int i = 0; i < n; i++) 
        if(val[find(i)]) a.pb(val[find(i)]);
    
    for(int i = T; i < T+m; i++) 
        if(val[find(i)]) b.pb(val[find(i)]);

    if(a.size() == n and b.size() == m) {
        cout << "Yes" << endl;
        for(auto x : a) cout << x << " ";
        cout << endl;
        for(auto x : b) cout << x << " ";
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

