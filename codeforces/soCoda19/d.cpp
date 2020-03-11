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
const ll MOD = 1e9 + 7;

ll calc(ll x, ll b) {
    ll qtd = x/b;
    qtd = min(qtd,b-1);

    ll ans = (x * qtd) % MOD;
    ans = (ans + (((qtd*(qtd-1))>>1) % MOD)) % MOD;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll a,b; cin >> a >> b;
    ll ans = 0;

    for(ll x = b+1; x/b <= a; x += b) {
        ans = (ans + calc(x,b)) % MOD;
    }

    cout << ans << endl;

    return 0;
}

