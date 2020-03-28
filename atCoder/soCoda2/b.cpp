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
const int T = 1e4 + 3;

int n;
int c[T];
int in[T];
int ans[T];
ll r;

vector<int> g[T];
vii v;

void bfs(int at) {
    queue<int> fila;
    fila.push(at);
    int p = 0;

    while(!fila.empty()) {
        at = fila.front();
        fila.pop();
        ans[at] = c[p++];
        r += (ll)ans[at];
        vii tmp;

        for(int nxt : g[at]) {
            if(ans[nxt]) continue;
            tmp.eb(in[nxt],nxt);
        }

        sort(tmp.begin(), tmp.end());
        for(auto x : tmp) fila.push(x.se);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
        in[a]++, in[b]++;
    }

    for(int i = 1; i <= n; i++) v.eb(in[i],i);
    for(int i = 0; i < n; i++) cin >> c[i];
    sort(c,c+n,greater<int>());
    bfs(v[0].se);

    cout << r - c[0] << endl;
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

