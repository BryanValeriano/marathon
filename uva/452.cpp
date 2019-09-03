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

const int T = 30;
int in[T];
int t[T];
int vis[T];
int acum[T];
vector<int> g[T];
vector<int> tem;
int v;

void init() {
    for(int i = 0; i < T; i++) {
        g[i].clear();
        in[i] = 0;
        acum[i] = 0;
    }
    tem.clear();
}

void pre(string x) {
    int at = x[0] - 'A';
    tem.pb(at);
    string y, z;
    int i = 2;
    while(i < x.size() and x[i] >= '0' and x[i] <= '9') y += x[i++];
    i++;
    while(i < x.size() and x[i] >= 'A' and x[i] <= 'Z') z += x[i++];
    t[at] = stoi(y);
    acum[at] = t[at];
    for(i = 0; i < z.size(); i++) {
        g[z[i] - 'A'].pb(at);
        in[at]++;
    }
}

int dfs(int u) {
    vis[u] = v;
    int ans = acum[u];
    for(auto h : g[u]) {
        in[h]--;
        acum[h] = max(acum[h], t[h] + acum[u]);
        if(vis[h] != v and !in[h]) {
            ans = max(ans, dfs(h));
        }
    }
    return ans;
}

void solve() {
    v++;
    int ans = 0;
    for(int i = 0; i < tem.size(); i++) 
        if(!in[tem[i]] and vis[tem[i]] != v) ans = max(ans,dfs(tem[i]));
    cout << ans << endl; 
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    string x;
    getline(cin,x);
    getline(cin,x);

    while(tc--) {
        init();
        getline(cin, x); 
        while(x != "") {
            pre(x);
            getline(cin,x);
        }
        solve();
        if(tc) cout << endl;
    }
    return 0;
}

