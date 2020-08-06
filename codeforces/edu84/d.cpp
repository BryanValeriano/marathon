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
const int T = 2e5+5;
const int LOG = log2(T)+2;

int p[T], cor[T], ori[T], anc[T][LOG];
bool vis[T];
vector<int> cs[T];
int res;

int sob(int pos, int k) {
    for(int i = LOG-1; i >= 0; i--)
        if(k-(1<<i) >= 0) pos = anc[pos][i], k -= (1<<i);
    return pos;
}

void check(const vector<int> &cycle) {
    int n = cycle.size();
    res = min(res,n);

    for(int x = 1; x*x <= n; x++) {
        if(n%x) continue;
        for(int wtf = 0; wtf < 2; wtf++) {
            int i = (wtf?x:n/x);
            if(i >= res) continue;
            for(int j = 0; j < n/i; j++) cs[j].clear();
            for(int j = 0; j < n; j++) cs[(j+1)%i].pb(cycle[j]);
            for(int p = 0; p < i; p++) {
                bool ok = 1;
                for(int k = 1; k < n/i; k++)
                    ok &= cor[ori[sob(cs[p][k],i-1)]] == cor[ori[sob(cs[p][k-1],i-1)]];
                if(ok) res = min(res,i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        res = n;
        for(int i = 1; i <= n; i++) {
            cin >> p[i], vis[i] = 0;
            ori[p[i]] = i;
            if(i == p[i]) res = 1;
        }
        for(int i = 1; i <= n; i++) cin >> cor[i];
        if(res==1) { cout << 1 << endl; continue; }

        for(int i = 1; i <= n; i++) anc[p[i]][0] = p[p[i]];
        for(int i = 1; i < LOG; i++)
            for(int j = 1; j <= n; j++)
                anc[j][i] = anc[anc[j][i-1]][i-1];

        for(int i = 1; i <= n; i++) {
            if(vis[i]) continue;
            vector<int> cycle;
            for(int j = i; !vis[j]; j = p[j]) cycle.pb(j), vis[j] = 1;
            check(cycle);
        }
        cout << res << endl;
    }
    return 0;
}
