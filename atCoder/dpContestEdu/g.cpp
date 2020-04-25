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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<int> in(n,0);
    vector<int> ans(n,0);
    vector<vector<int>> g(n,vector<int>());

    while(m--) {
        int x,y; cin >> x >> y;
        x--;y--;
        g[y].pb(x);
        in[x]++;
    }

    queue<int> edges;
    for(int i = 0; i < n; i++)
        if(!in[i]) edges.push(i);

    int best = 0;

    while(!edges.empty()) {
        int u = edges.front();
        edges.pop();
        best = max(best,ans[u]);
        for(int v : g[u]) {
            in[v]--;
            ans[v] = max(ans[v], ans[u]+1);
            if(!in[v]) edges.push(v);
        }
    }

    cout << best << endl;

    return 0;
}

