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

const int T = 505;
int in[T];
int last[T];
bool vis[T][T];
vector<int> ans;
vector<int> g[T];
int n, m;

void init() {
    int x,y;
    memset(in, 0, sizeof in);
    memset(vis, 0, sizeof vis);
    ans.clear();
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x;
        last[x] = i;
        g[i].clear();
    }
    g[n].clear();

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        if(last[x] > last[y]) swap(x,y);
        g[y].pb(x);
        in[x]++;
        vis[x][y] = vis[y][x] = 1;
    }

    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            if(!vis[i][j]) {
                int ii = i, jj = j;
                if(last[ii] < last[jj]) swap(ii,jj);
                g[jj].pb(ii);
                in[ii]++;
                vis[ii][jj] = vis[jj][ii] = 1;
            }
}

void solve() {
    queue<int> lista; 
    for(int i = 1; i <= n; i++) if(!in[i]) lista.push(i);

    while(!lista.empty()) {
        int at = lista.front();
        lista.pop();
        ans.pb(at);
        for(auto x : g[at]) {
            in[x]--;
            if(!in[x]) lista.push(x);
        }
    }

    if(ans.size() == n) {
        for(int i = 0; i < n; i++) cout << ans[i] << (i+1 == n? "" : " ");
    } else cout << "IMPOSSIBLE"; 
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; 
    cin >> tc;
    while(tc--) {
        init();
        solve();
    }
    return 0;
}

