#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long double ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 6e5 + 10;

ll v[T];
vector<ll> ve;
map<ll,ll> id;
ll qtd[T + 10];
ll acum[T + 10];
int n;

void update(int pos, int tipo, ll val) {
    for(; pos <= T; pos += (pos & -pos)) {
        if(tipo == 0) qtd[pos] += val;
        else acum[pos] += val;
    }
}

ll query(int pos, int tipo) {
    if(pos < 1) return 0;
    if(pos > T) pos = T;
    ll ans = 0;
    for(;pos; pos -= (pos & -pos)) {
        if(tipo == 0) ans += qtd[pos];
        else ans += acum[pos];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        ve.pb(v[i]);
        ve.pb(v[i]+1);
        ve.pb(v[i]-1);
    }

    reverse(v+1, v+n+1);

    sort(ve.begin(), ve.end());
    ve.resize(unique(ve.begin(), ve.end()) - ve.begin());

    for(int i = 0; i < ve.size(); i++) 
        id[ve[i]] = i+1;

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll soma = query(T, 1) - query(id[v[i]]+1, 1);
        ll qtdmais = query(T, 0) - query(id[v[i]]+1, 0);
        ll sub = query(id[v[i]] - 2, 1);
        ll qtdmenos = query(id[v[i]] - 2, 0);

        ll x = (soma - (qtdmais * v[i]));
        ll y = ((qtdmenos * v[i]) - sub);
        x -= y;
        ans += x;

        update(id[v[i]], 0, 1);
        update(id[v[i]], 1, v[i]);

    }
    cout << setprecision(0) << fixed << ans << '\n';
    return 0;
}

