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

const int T = 5e4 + 2;
const int K = 502;

vector<int> g[T];
ll dist[T][K];
ll ans;
int n,k;

void dfs(int u, int pai) {
    dist[u][0] = 1;

    for(int v : g[u]) {
        if(v == pai) continue;
        dfs(v,u);

        for(int i = 0; i < k; i++)
            if(dist[v][i] and k-i-1 > 0)
                ans += (dist[v][i] * dist[u][k-i-1]);

        dist[u][1]++;
        for(int i = 1; i < k; i++)
            if(dist[v][i]) dist[u][i+1] += dist[v][i];
    }

    ans += dist[u][k];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;

    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(1,1);

    cout << ans << endl;

    return 0;
}

