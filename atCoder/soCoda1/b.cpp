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
const ll INF = 2e18;
const double PI = acos(-1.0);

ll solve(ll l, ll c) {
    ll ans = INF;

    //corta na linha
    for(ll i = 1; i <= l/2; i++) {
        ll area1 = c*i;
        ll sobraL = l-i;
        ll x = max(abs(area1 - (sobraL/2)*c), abs(area1 - (sobraL/2+(sobraL&1))*c));
        ll y = max(abs(area1 - (c/2)*sobraL), abs(area1 - (c/2+(c&1))*sobraL));
        ans = min({ans,x,y});
    }

    //corta na coluna
    for(ll i = 1; i <= c/2; i++) {
        ll area1 = l*i;
        ll sobraC = c-i;
        ll x = max(abs(area1 - (sobraC/2)*l), abs(area1 - (sobraC/2+(sobraC&1))*l));
        ll y = max(abs(area1 - (l/2)*sobraC), abs(area1 - (l/2+(l&1))*sobraC));
        ans = min({ans,x,y});
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll l,c; cin >> l >> c;
    cout << solve(l,c) << endl;
    return 0;
}

