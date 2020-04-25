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

const int T = 2e5 + 2;
ll v[T];
bool vis[T];
vector<int> g[T];
int n,q;

void dfs(int at) {
    vis[at] = 1;
    for(int nxt : g[at]) {
        if(!vis[nxt]) {
            v[nxt] += v[at];
            dfs(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    ll a,b;

    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    while(q--) {
        cin >> a >> b;
        v[a] += b;
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
        cout << v[i] << " ";
    }
    cout << endl;


    return 0;
}

