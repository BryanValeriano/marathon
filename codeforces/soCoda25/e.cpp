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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5 + 2;
ll a[T],b[T];
ll acumB, acumA;
vii v;
int n,m;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i], v.eb(a[i],0);
    for(int i = 1; i <= m; i++) cin >> b[i], acumB += b[i], v.eb(b[i],1);

    sort(v.begin(),v.end());

    ll qtdA = 0;
    ll faltaB = m;
    ll ans = 2e18;

    for(ii x : v) {
        ans = min(ans, x.fi*qtdA - acumA + acumB - x.fi*faltaB);
        if(x.se) acumB -= x.fi, faltaB--;
        else acumA += x.fi, qtdA++;
    }

    cout << ans << endl;
    return 0;
}

