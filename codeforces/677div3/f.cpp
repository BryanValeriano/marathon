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
const ll INF = 1e9;
const double PI = acos(-1.0);
int n,m,k,ok;

ll dp[71][71][36][71];
bool vis[71][71][36][71];
vector<ll> v[71];

ll solve(int lin, int col, int qtd, int mod) {
    if(qtd > ok) return -INF;

    ll &r = dp[lin][col][qtd][mod];
    if(vis[lin][col][qtd][mod]) return r;
    vis[lin][col][qtd][mod] = 1;

    if(col == m) return r = (qtd <= ok? solve(lin+1,0,0,mod) : -INF);
    if(lin == n) return r = (mod ? -INF : 0);

    return r = max(solve(lin,col+1,qtd+1,(mod+v[lin][col])%k)+v[lin][col],
            solve(lin,col+1,qtd,mod));

}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            ll x; cin >> x;
            v[i].pb(x);
        }
    }
    ok = m/2;

    cout << max(0ll,solve(0,0,0,0)) << endl;
    return 0;
}

