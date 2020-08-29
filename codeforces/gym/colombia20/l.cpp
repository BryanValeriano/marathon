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

struct node {
    int fromPar, dist;
    bool vis;
    vector<node*> adj;
    node() : fromPar(-1), dist(-1), vis(false), adj(4, nullptr) {}
    void addEdge(node* n, int dir) {
        if (!n) return;
        adj[dir] = n;
        n->adj[dir ^ 3] = this;
    }
};

void bfs(node* st, node* fin) {
    st->dist = 0;
    st->vis = true;
    queue<node*> q;
    q.push(st);
    while (!q.empty()) {
        node* x = q.front(), *y;
        q.pop();
        for (int i = 0;i < 4;i++) {
            if (!(y = x->adj[i])) continue;
            if (y->vis) continue;
            y->vis = true;
            y->dist = x->dist + 1;
            y->fromPar = i;
            if (y == fin) return;
            q.push(y);
        }
    }
}

string path(node* st, node* fin) {
    string ans = "", dirs = "DLRU";
    while (fin != st) {
        ans += dirs[fin->fromPar];
        fin = fin->adj[fin->fromPar ^ 3];
    }
    return string(ans.rbegin(), ans.rend());
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> mapa(n);
    vector<vector<node*>> g(n, vector<node*>(m, nullptr));
    vector<node*> lastc(m, nullptr);
    node *st, *fin;
    for (int i = 0;i < n;i++) {
        cin >> mapa[i];
        node *lastl = nullptr;
        for (int j = 0;j < m;j++) {
            if (mapa[i][j] == 'X') continue;
            g[i][j] = new node;
            if (mapa[i][j] == 'S') st = g[i][j];
            else if (mapa[i][j] == 'E') fin = g[i][j];
            if (lastl) g[i][j]->addEdge(lastl, 1);
            if (lastc[j]) g[i][j]->addEdge(lastc[j], 3);
            lastl = lastc[j] = g[i][j];
        }
    }
    bfs(st, fin);
    cout << fin->dist << endl;
    if (fin->dist != -1) cout << path(st, fin) << endl;
    return 0;
}