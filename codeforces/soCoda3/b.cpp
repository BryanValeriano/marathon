#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 4e3+100;
const int LOG = log2(T)+2;
const int S = sqrt(T);

int d,n,t;
int p[T], anc[T][LOG], nivel[T];
int in[T], out[T], id[T];

vti qrs;
vector<int> g[T];

int freq[T];
set<int> bag;
multiset<int> pesos;

void read() {
    cin >> d >> n;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
}

int lca(int u, int v) {
    if(nivel[u] < nivel[v]) swap(u,v);

    for(int i = LOG-1; i >= 0; i--)
        if(nivel[u] - (1 << i) >= nivel[v]) u = anc[u][i];

    if(u == v) return u;

    for(int i = LOG-1; i >= 0; i--) {
        if(anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }

    return anc[u][0];
}

void lin(int u, int pai) {
    id[++t] = u;
    in[u] = t;

    for(int v : g[u]) {
        if(v == pai) continue;
        anc[v][0] = u;
        nivel[v] = nivel[u]+1;
        lin(v,u);
    }

    id[++t] = u;
    out[u] = t;
}

void buildLca() {
    memset(nivel, INF, sizeof nivel);
    nivel[1] = 0;
    lin(1,1);

    for(int j = 1; j < LOG; j++)
        for(int i = 1; i <= n; i++)
            anc[i][j] = anc[anc[i][j-1]][j-1];
}

bool cmp(const ti &a, const ti &b) {
    int x1 = get<0>(a);
    int y1 = get<1>(a);

    int x2 = get<0>(b);
    int y2 = get<1>(b);

    if(x1/S != x2/S) return x1/S < x2/S;
    return y1 > y2;
}

void buildQueries() {
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            int u = i;
            int v = j;
            if(in[u] > in[v]) swap(u,v);
            int low = lca(u,v);
            //cout << u << " " << v << " " << low << endl;
            if(low == u) qrs.eb(in[u],in[v],0);
            else qrs.eb(out[u],in[v],low);
        }
    }

    sort(qrs.begin(), qrs.end(), cmp);
}


void tira(int x) {
    freq[x]--;

    if(freq[x] == 0) {
        if(bag.count(x)) bag.erase(x);
        if(pesos.count(p[x])) pesos.erase(pesos.find(p[x]));
    }

    else if(freq[x] == 1) {
        bag.insert(x);
        pesos.insert(p[x]);
    }
}

void add(int x) {
    freq[x]++;

    if(freq[x] == 1) {
        bag.insert(x);
        pesos.insert(p[x]);
    }

    else if(freq[x] == 2) {
        if(bag.count(x)) bag.erase(x);
        if(pesos.count(p[x])) pesos.erase(pesos.find(p[x]));
    }
}

int check(int low) {

    int maxi = *pesos.rbegin();
    int mini = *pesos.begin();

    //for(auto x : bag) cout << x << ", ";
    //cout << endl;

    if(low) {
        mini = min(mini,p[low]);
        maxi = max(maxi,p[low]);
    }

    //cout << maxi << " " << mini << " -> " << (maxi-mini <= d) << endl;

    return (maxi - mini <= d);
}

int mo() {
    int l = 1, r = 1, ans = 0;
    add(1);

    for(int i = 0; i < qrs.size(); i++) {
        int x,y,p;
        tie(x,y,p) = qrs[i];

        while(l < x) tira(id[l++]);
        while(l > x) add(id[--l]);
        while(r < y) add(id[++r]);
        while(r > y) tira(id[r--]);

        //cout << x << " " << y << " " << p << " = " << endl;
        ans += check(p);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    read();
    buildLca();
    buildQueries();
    cout << mo() << endl;
    return 0;
}

