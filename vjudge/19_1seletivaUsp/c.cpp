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

const int T = 5e4 + 5;
vector<int> g[T];
int peso[T];
int n;

set<int> bag;
unordered_map<int,int> ind;

void init() {
    bag.clear();
    ind.clear();
    for(int i = 0; i < T; i++) g[i].clear();
}

void dfs(int u, int op) {
    if(op) bag.insert(peso[u]);
    else bag.erase(peso[u]);

    for(auto z : g[u]) { 
        if(op) bag.insert(peso[z]);
        else bag.erase(peso[z]);
    }

}

int main() {
    ios::sync_with_stdio(false);
    int tc, x, y; cin >> tc;
    while(tc--) {
        init();
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> peso[i], bag.insert(peso[i]), ind[peso[i]] = i;

        for(int i = 0; i < n-1; i++) {
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }

        for(int i = 1; i <= n; i++) {
            dfs(i,0);
            if(bag.size()) cout << ind[*bag.rbegin()] << " ";
            else cout << 0 << " ";
            dfs(i,1);
        }
        cout << endl;

    }
    return 0;
}

