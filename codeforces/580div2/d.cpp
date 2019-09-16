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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 63;

vector<int> g[T];
ll fdp[T];
int qtd[T];
int dist[T];
int out[T];
int ans = INF;
int n;

void dfs(int u, int pai) {
    for(int v : g[u]) {
        if(dist[v] and (!out[v]) and v != pai) {
            ans = min(ans, (dist[u] - dist[v])+1);
        }
        else if(!dist[v] and qtd[v] > 1) {
            dist[v] = dist[u]+1;
            dfs(v,u);
        }
    }
    out[u] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;

        for(int j = 0; j < T; j++) {
            if((x & (1ll << j))) {
                qtd[j]++;
                fdp[j] |= x;
            }
        }
    }


    for(int i = 0; i < T; i++) {
        for(int j = i+1; j < T; j++) {
            if(qtd[i] > 1 and qtd[j] > 1 and fdp[i] & (1ll << j)) {
                g[i].pb(j), g[j].pb(i);
            }
        }
    }

    for(int i = 0; i < T; i++) {
        if(qtd[i] > 1 and (!dist[i])) {
            dist[i] = 1;
            dfs(i,i);
        }
    }

    cout << (ans == INF? -1 : ans) << endl;

    return 0;
}

