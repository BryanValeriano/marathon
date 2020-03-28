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
const ll INF = 1e18;
const double PI = acos(-1.0);
const int T = 502;

vector<int> pilha;
vector<int> atv;

ll ans[T];
ll g[T][T];
ll adj[T][T];
int n;

void update() {
    int at = pilha.back();
    pilha.pop_back();

    atv.pb(at);

    for(int x = 1; x <= n; x++)
        for(int y = 1; y <= n; y++)
            adj[x][y] = min(adj[x][y], adj[x][at] + adj[at][y]);

    for(auto x : atv)
        for(auto y : atv)
            ans[pilha.size()] += adj[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> adj[i][j];

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        pilha.pb(x);
    }

    while(pilha.size()) update();
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

