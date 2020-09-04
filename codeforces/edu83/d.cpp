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
const int MOD = 998244353;
const int N = 2e5+5;
ll fat[N], topo[N];

ll ele(ll base, ll e) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = (ans*base)%MOD;
        base = (base*base)%MOD;
        e >>= 1;
    }
    return ans;
}

ll inv(ll x) {
    return ele(x,MOD-2);
}

ll comb(ll a, ll b) {
    if(b > a) return 0;
    return fat[a]*inv(fat[b]*fat[a-b]%MOD)%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    fat[0] = 1;
    for(ll i = 1; i < N; i++) fat[i] = (i*fat[i-1])%MOD;

    ll n,m; cin >> n >> m;
    if(n < 3) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;

    for(ll i = m; i >= 2; i--) {
        // escolho n-2 elementos
        // = (n - topo ja definido e o elemento q vai ser repetido)
        // de (i-1) opcoes (i-1 sao todos os valores menores q topo definido)
        // pra cada uma dessas formas de escolher n-2 elementos,
        // tenhos n-2 casas q posso escolher para ser o elemento repetido
        // cada elemento de topo[i] pode ser representado como uma tupla
        // = ({set de elementos(n-1 elementos no total)}, topo, elemento repetido)
        topo[i] = (comb(i-1,n-2)*(n-2))%MOD;
        topo[i] = (topo[i]+topo[i+1])%MOD;
        cout << i << " " << topo[i] << endl;
    }

    for(ll i = 2; i < n; i++) {
        int j = max(i,n-i+1);
        if(j > m) continue;
        // pra cada tupla, ja tenho definido o topo e o repetido
        // entao sobra n-3 elementos do set para serem escolhidos
        // desses n-3, devo escolher i-2 (meno topo e repetido a esquerda)
        // para estarem a esquerda do topo
        ll c = comb(n-3,i-2);
        ans = (ans + (c*topo[j])%MOD)%MOD;
    }

    cout << ans << endl;

    return 0;
}

