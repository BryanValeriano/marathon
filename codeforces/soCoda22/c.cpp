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
const int T = 1e5 + 2;
ll v[T];
ll acum[T];
ll n,k;

bool check(int qtd, int x) {
    if(x-qtd+1 < 0) return 0;
    int borda = x-qtd+1;

    ll tot = v[x] * (qtd-1);
    ll cost = acum[borda] - acum[x];

    return (tot-cost <= k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v,v+n);

    acum[n-1] = v[n-1];
    for(int i = n-2; i >= 0; i--) acum[i] += acum[i+1] + v[i];

    ll qtd = 0;
    ll ans = 0;

    for(int i = 0; i < n; i++) {
        ll l = 0;
        ll r = n;
        ll qtdTmp = 0;

        while(l <= r) {
            ll mid = (l+r) >> 1;
            if(check(mid,i)) qtdTmp = mid, l = mid+1;
            else r = mid-1;
        }

        if(qtdTmp > qtd) {
            qtd = qtdTmp;
            ans = v[i];
        }
    }

    cout << qtd << " " << ans << endl;



    return 0;
}

