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
const int T = 302;
const int LOG = log2(T*T) + 5;

int h,w,d;

int g[T][T];
int l[T*T];
int c[T*T];
int niv[T*T];
int anc[T*T][LOG];
ll cost[T*T][LOG];

void build() {
    for(int i = 1; i <= h*w; i++) {
        if(i + d <= h*w) {
            anc[i][0] = i+d;
            cost[i][0] = abs(c[i]-c[i+d]) + abs(l[i]-l[i+d]);
            niv[i+d] = niv[i]+1;
        }
    }

    for(int j = 1; j < LOG; j++)
        for(int i = 1; i <= h*w; i++) {
            anc[i][j] = anc[anc[i][j-1]][j-1];
            cost[i][j] = cost[i][j-1] + cost[anc[i][j-1]][j-1];
        }
}

ll query(int u, int v) {
    ll ans = 0;

    for(int i = LOG-1; i >= 0; i--) {
        if(niv[u] + (1 << i) <= niv[v]) {
            ans += cost[u][i];
            u = anc[u][i];
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> h >> w >> d;

    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++) {
            cin >> g[i][j];
            l[g[i][j]] = i;
            c[g[i][j]] = j;
        }

    build();
    int q; cin >> q;
    while(q--) {
        int a,b; cin >> a >> b;
        cout << query(a,b) << endl;
    }

    return 0;
}

