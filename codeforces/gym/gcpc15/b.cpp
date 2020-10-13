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
const int T = 1e3+3;
int n;
int in[T];
bool vis[T];
vector<int> g[T];

void topoSort(queue<int> &lista) {
    while(!lista.empty()) {
        int at = lista.front();
        lista.pop();
        int best = INF, nxt = 0;

        for(int v : g[at]) {
            in[v]--;
            if(!vis[v] and in[v] < best) {
                best = in[v];
                nxt = v;
            }
        }

        if(best != INF) {
            lista.push(nxt);
            vis[nxt] = 1;
        }
    }
}

int solve() {
    int ans = 0;
    while(1) {
        queue<int> lista;
        for(int i = 0; i < n; i++)
            if(!vis[i] and !in[i]) lista.push(i), ans++, vis[i] = 1;
        if(lista.empty()) return ans;
        topoSort(lista);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            int x; cin >> x;
            in[x]++;
            g[i].pb(x);
        }
    }

    cout << solve() << endl;
    return 0;
}

