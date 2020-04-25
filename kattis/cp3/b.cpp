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
const double PI = acos(-1.0);
const ll INF = 1e13;

const int T = (1 << 17);
const int N = 17;
const int NN = 1e5 + 3;

ll dp[T][N];
int ss[N];
ll dist[N][NN];
vii g[NN];

void dij(int pos, int ori) {
    for(int i = 0; i < NN; i++) dist[pos][i] = INF;
    dist[pos][ori] = 0;

    priority_queue<ii,vii,greater<ii>> pq;
    pq.emplace(0,ori);

    while(!pq.empty()) {
        ii at = pq.top();
        pq.pop();

        int v = at.se;
        ll d = at.fi;
        if(dist[pos][v] < d) continue;

        for(ii nxt : g[v]) {
            int prox = nxt.fi;
            ll dd = nxt.se;
            if(dist[pos][prox] > d+dd) {
                dist[pos][prox] = d+dd;
                pq.emplace(d+dd,prox);
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    int n,m,s;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int x,y,d; cin >> x >> y >> d;
        g[x].eb(y,d);
        g[y].eb(x,d);
    }

    cin >> s;
    for(int i = 0; i < s; i++) {
        cin >> ss[i];
        dij(i,ss[i]);
    }
    ss[s] = 0;
    dij(s,ss[s]);
    s++;

    int gol = (1 << s);
    for(int i = 0; i < gol; i++)
        for(int j = 0; j < s; j++)
            dp[i][j] = INF;

    dp[0][s-1] = 0;

    for(int mask = 0; mask < gol; mask++)
        for(int last = 0; last < s; last++)
            for(int j = 1, casa = 0; j < gol; j <<= 1, casa++)
                dp[mask|j][casa] = min(dp[mask|j][casa], dp[mask][last] + dist[last][ss[casa]]);

    cout << dp[gol-1][s-1] << endl;
    return 0;
}

