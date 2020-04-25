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
const ll MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    n++;
    vector<ll> v(n+1);
    for(ll i = 1; i <= n; i++) v[i] = (v[i-1]+i)%MOD;
    ll ans = 0;
    for(ll i = k; i <= n; i++) {
        ll mini = v[i];
        ll maxi = (v[n]-v[n-i]+MOD)%MOD;
        ll tmp = (maxi-mini+1+MOD)%MOD;
        ans = (ans+tmp)%MOD;
    }
    cout << ans << endl;
    return 0;
}

