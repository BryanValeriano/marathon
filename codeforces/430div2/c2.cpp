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
const int T = 2e5+5;

vector<int> g[T];
vector<int> tmp;
int ans[T];
int vis[T];
int c[T];
int vez;

void dfs(int at, int val, int prob) {
    vis[at] = vez;
    int ok = __gcd(val,at==prob?0:c[at]);
    ans[at] = max(ans[at],ok);
    if(ok < val and vez==1) tmp.pb(at);
    for(int v : g[at]) {
        if(vis[v]==vez) continue;
        dfs(v,ok,prob);
    }
}

void calc(int x) {
    ++vez;
    dfs(1,0,x);
}


int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    cin.tie(0); cout.tie(0);

    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    ++vez;
    tmp.pb(1);
    dfs(1,0,0);

    for(int x : tmp) calc(x);
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}

