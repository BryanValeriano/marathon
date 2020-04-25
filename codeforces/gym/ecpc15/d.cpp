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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5 + 3;
vector<ii> g[T];
ll mini[T];
ll tempo[T];
vector<ll> times;

void init(int n) {
    for(int i = 1; i <= n; i++) {
        g[i].clear();
        mini[i] = INF;
    }
    times.clear();
}
void bfs() {
    queue<int> fila;
    fila.push(1);
    tempo[1] = 0;
    while(!fila.empty()) {
        int at = fila.front();
        fila.pop();
        for(auto v : g[at]) {
            tempo[v.fi] = mini[at] + (v.se-mini[at])*2ll + tempo[at];
            fila.push(v.fi);
        }
        if(g[at].empty()) times.pb(tempo[at]);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        init(n);
        for(int i = 2; i <= n; i++) {
            ll p,c; cin >> p >> c;
            g[p].eb(i,c);
            mini[p] = min(mini[p],c);
        }
        bfs();
        sort(times.begin(),times.end());
        int q; cin >> q;
        while(q--) {
            ll x; cin >> x;
            int pos = upper_bound(times.begin(),times.end(),x) - times.begin();
            cout << pos << endl;
        }
    }
    return 0;
}

