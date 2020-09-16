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
    graph() : size(0) {}
    void addEdge(string a, string b) {
        int x = addNode(a);
        int y = addNode(b);
        adj[x].push_back(y);
    }
    int addNode(string s) {
        if (!conv.count(s)) {
            conv[s] = size++;
            adj.emplace_back();
        }
        return conv[s];
    }
};

bool dfs(graph& g, int u, int t, int p = -1) {
    if (u == t) return true;
    bool found = false;
    for (auto v : g.adj[u]) {
        if (v == p) continue;
        if (dfs(g, v, t, u)) {
            found = true;
            break;
        }
    }
    return found;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string u, t, v;
    graph g;
    for (int i = 0;i < n;i++) {
        cin >> u >> t >> t >> t >> v;
        g.addEdge(u, v);
    }
    vector<string> as = {"Pants on Fire", "Fact", "Alternative Fact"};
    for (int i = 0;i < m;i++) {
        cin >> u >> t >> t >> t >> v;
        int ans = 0;
        if (g.conv.count(u) and g.conv.count(v)) {
            ans += dfs(g, g.conv[u], g.conv[v]);
            if (!ans) {
                ans += 2 * dfs(g, g.conv[v], g.conv[u]);
            }
            cout << as[ans] << endl;
        } 
        else cout << as[0] << endl;
    }
    return 0;
}

