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

int n, m;

const int T = 1e5 + 5;
bitset<T> vis;
int v[T];
vector<int> g[T];

int dfs(int at, int c) {
    vis[at] = 1;
    if(v[at]) c++;
    else c = 0;

    if(c > m) return 0;

    int ans = (g[at].size() == 1) && (at != 1);
    
    for(int x : g[at]) 
        if(!vis[x]) ans += dfs(x,c);    
    
    return ans;

}


int main() {
    ios::sync_with_stdio(false);
    int x,y;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) 
        cin >> v[i];

    for(int i = 0; i < n-1; i++) {
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    cout << dfs(1, 0) << endl;

    return 0;
}

