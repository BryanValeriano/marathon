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

struct graph {
    int size;
    vector<list<int>> adj;
    map<string, int> conv;
    graph(int n) : size(0), adj(n) {}
    void addEdge(string& a, string& b) {
        int x = addNode(a);
        int y = addNode(b);
        adj[x].push_back(y);
    }
    int addNode(string& s) {
        if (!conv.count(s)) {
            conv[s] = size++;
        }
        return conv[s];
    }
};

vector<bool> vis;
void dfs(graph& g, int u) {
    vis[u] = true;
    for (int v : g.adj[u]) {
        if (vis[v]) continue;
        dfs(g, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    graph g(n);
    string s, t;
    int x;
    vector<int> idx;
    for (int i = 0;i < n;i++) {
        cin >> s >> x;
        g.addNode(s);
        for (int j = 0;j < x;j++) {
            cin >> t;
            g.addEdge(t, s);
        }
        size_t pos = s.find_last_of(':');
        if (s.substr(pos + 1) == "PROGRAM") idx.push_back(g.conv[s]);
    }
    vis.assign(n, false);
    for (int id : idx) if (!vis[id]) dfs(g, id);
    int ans = n;
    for (int i = 0;i < g.size;i++) ans -= vis[i];
    cout << ans << endl;
    return 0;
}
