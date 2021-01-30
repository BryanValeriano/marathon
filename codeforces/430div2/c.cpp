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
int ans[T][2];
bool vis[T];
int c[T];

void solve(int at) {
    queue<int> fila;
    fila.push(at);

    ans[at][0] = c[at];
    ans[at][1] = 0;
    vis[at] = 1;

    while(!fila.empty()) {
        int at = fila.front();
        fila.pop();
        for(int v : g[at]) {
            if(vis[v]) continue;
            ans[v][0] = __gcd(ans[at][0],c[v]);
            ans[v][1] = max(__gcd(ans[at][1],c[v]), __gcd(ans[at][0],0));
            fila.push(v);
            vis[v] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    solve(1);
    for(int i = 1; i <= n; i++)
        cout << max(ans[i][0],ans[i][1]) << " ";
    cout << endl;
    return 0;
}

