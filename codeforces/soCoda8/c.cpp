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


map<ll,ll> zero;
map<ll,ll> um;

int main() {
    int n; cin >> n;
    ll k; cin >> k;
    ll ans = 0;

    while(n--) {
        ll x; cin >> x;
        if(x % k == 0) ans += um[x/k];
        if(x % k == 0) um[x] += zero[x/k];
        zero[x]++;
    }

    cout << ans << endl;

    return 0;
}

