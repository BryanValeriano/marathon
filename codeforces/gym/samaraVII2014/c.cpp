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

const int T = 1e5 + 3;
int n, m;
vii g[T];
int vis[T][2];
int v;

bool dfs(int at, int peg, int c) {
    if(at == n) return true;
    vis[at][peg] = v;
    bool ans = false;
    for(auto z : g[at]) {
        if(z.se > c and !peg and vis[z.fi][1] != v) ans |= dfs(z.fi,1,c);
        else if(z.se <= c and vis[z.fi][peg] != v) ans |= dfs(z.fi,peg,c);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int a,b,c;

    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a].eb(b,c);
        g[b].eb(a,c);
    }

    int l = 0, r = 1e9;

    while(l <= r) {
        v++;
        int mid = (l+r) >> 1;
        if(dfs(1,0,mid)) r = mid-1;
        else l = mid+1;
    }

    cout << (l == 1e9 + 1? -1 : l) << endl;

    return 0;
}

