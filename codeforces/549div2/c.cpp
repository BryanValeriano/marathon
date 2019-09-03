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
vector<int> g[T];
bool peso[T];
set<int> ans;

void dfs(int u) {
    int check = 0;
    for(auto v : g[u]) {
        check += peso[v];
        dfs(v);
    }
    if(check == g[u].size() and peso[u] == 1) ans.insert(u);
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int x,y;
    int root;

    for(int i = 1; i <= n; i++) {
        cin >> x >> y;
        if(x != -1) g[x].pb(i);
        else root = i;
        peso[i] = y;
    }

    dfs(root);
    if(ans.size() > 0) for(auto z : ans) cout << z << " ";
    else cout << -1;
    cout << endl;


    return 0;
}

