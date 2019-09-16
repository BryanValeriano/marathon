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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 30;
ll v[T];

int main() {
    ios_base::sync_with_stdio(false);
    ll n,s; cin >> n >> s;

    v[0] = 1;
    int lim = n;

    for(int i = 1; i <= n; i++) {
        ll x; cin >> x;
        if(s/x >= v[i-1]) v[i] = v[i-1]*x;
        else { lim = i-1; break; }
    }

    ll ans = 0;

    while(lim >= 0) {
        ll vez = s/v[lim];
        s -= vez*v[lim];
        ans += vez;
        lim--;
        if(!s) break;
    }

    cout << ans << endl;

    return 0;
}

