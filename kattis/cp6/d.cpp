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
const int T = 1e6+5;
vector<int> g[T];
int in[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    while(m--) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        in[b]++;
    }
    vector<int> ans;
    queue<int> fila;
    for(int i = 1; i <= n; i++)
        if(!in[i])
            fila.push(i);
    while(!fila.empty()) {
        int at = fila.front();
        ans.pb(at);
        fila.pop();
        for(int v : g[at]) {
            in[v]--;
            if(!in[v]) fila.push(v);
        }
    }
    if(ans.size() == n) {
        for(int i = 0; i < n; i++) cout << ans[i] <<endl;
    } else cout << "IMPOSSIBLE\n";
    return 0;
}

