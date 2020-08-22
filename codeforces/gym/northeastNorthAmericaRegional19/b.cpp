#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e6+5;
const int N = T*2+10;

int n,m;
vector<int> g[N];
vector<int> ilha[N];
int low[N], d[N], st[N], rec[N], pai[N];
int sz,t;

void tarjan(int u) {
    st[sz++] = u;
    d[u] = low[u] = ++t;

    for(int v : g[u]) {
        if(!low[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        } else low[u] = min(low[u],d[v]);
    }
    if(low[u] >= d[u]) {
        int a;
        do {
            a = st[--sz];
            pai[a] = u;
            d[a] = INF;
        } while(a != u);
    }
}

bool sat() {
    for(int i = 0; i < N; i++)
        if(!low[i]) tarjan(i);

    for(int i = 0; i <= T; i++)
        if(pai[i] == pai[i+T])
            return false;

    return true;
}

void addOr(int x, int y) {
    g[x].pb(y >= T? y-T : y+T);
    g[y].pb(x >= T? x-T : x+T);
}

void addXor(int x, int y) {
    addOr(x,y);
    addOr(x >= T? x-T : x+T,y >= T? y-T : y+T);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> m >> n;

    for(int i = 0; i < m; i++) {
        int x;
        do {
            cin >> x;
            rec[x] += i;
            if(x)ilha[i].pb(x);
        } while(x);
    }

    for(int i = 0; i < m; i++) {
        for(int x : ilha[i]) {
            int c = rec[x]-i;
            if(i < c) addXor(i,c);
        }
    }

    cout << (sat()? "YES\n" : "NO\n");

    return 0;
}

