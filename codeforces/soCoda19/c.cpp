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
const ll INF = 2e18;
const double PI = acos(-1.0);

const int T = 1e5 + 4;
const int N = 202;
ll pre[T];
vector<ll> cost[T];
ll d[N];
int v[T];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    ll tot = 0;

    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        cost[v[i]].pb(x);
        tot += x;
    }

    ll ans = INF;
    ll qtd = 0;

    for(int i = 1; i < T; i++) {
        if(cost[i].empty()) continue;
        ll tmp = 0;

        for(ll j : cost[i]) tmp += j;

        tot -= tmp;
        ll tirou = 0;
        ll price = 0;
        ll tam = cost[i].size();

        for(int i = 1; i <= 200 and qtd-tirou >= tam; i++) {
            if(!d[i]) continue;

            //cout << i << ": " << qtd << " " << tirou << " " << tam << " | ";
            //cout << price << endl;

            if(qtd-tirou-d[i] >= tam) {
                price += i*d[i];
                tirou += d[i];
            } else {
                ll need = qtd-tirou-tam+1;
                price += need*i;
                tirou += need;
            }
        }

        //cout << tot+price << endl;

        ans = min(ans,tot+price);
        qtd += tam;
        for(ll x : cost[i]) d[x]++;
    }

    cout << ans << endl;

    return 0;
}

