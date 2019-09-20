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

ll euler(ll q, ll r) {
    r = (r&1? (r+1)/2*r : r/2*(r+1));
    q = (q&1? (q+1)/2*q : q/2*(q+1));
    return r-q;
}

int main() {
    ios_base::sync_with_stdio(false);
    ll a,b; cin >> a >> b;
    ll m = sqrt(b);
    ll ans = 0;

    for(ll f = 1; f <= m; f++)
        ans += f * (b/f - (a-1)/f) + euler(max(m, (a-1)/f), max(m, b/f));

    cout << ans << endl;

    return 0;
}

