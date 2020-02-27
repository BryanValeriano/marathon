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

const int T = 2e5 + 5;
const int LOG = 20;
int anc[T][LOG];
int niv[T];

int lca(int u, int v) {
    if(niv[u] < niv[v]) swap(u,v);

    for(int i = LOG-1; i >= 0; i--)
        if(niv[u] - (1 << i) >= niv[v])
            u = anc[u][i];

    if(u == v) return u;

    for(int i = LOG-1; i >= 0; i--) {
        if(anc[u][i] != anc[v][i] and anc[u][i] != 0) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }

    return anc[u][0];
}

void update(int i) {
    for(int j = 1; j < LOG; j++)
        anc[i][j] = anc[anc[i][j-1]][j-1];
}


int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    int u = 1, v = 1, ans = 0;

    niv[1] = 1;

    for(int i = 2; i <= n; i++) {
        int p; cin >> p;

        anc[i][0] = p;
        niv[i] = niv[p]+1;

        update(i);

        int low1 = lca(u,i);
        int x = (niv[u]+niv[i]) - 2*niv[low1];

        int low2 = lca(v,i);
        int y = (niv[v]+niv[i]) - 2*niv[low2];

        if(x >= y and x > ans) {
            ans = x;
            v = i;
        }

        else if(y > x and y > ans) {
            ans = y;
            u = i;
        }

        cout << ans << endl;
    }

    return 0;
}

