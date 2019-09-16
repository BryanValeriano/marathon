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

string s;
ll ib, is, ic;
ll nb, ns, nc;
ll pb, ps, pc;
ll cash;

bool check(ll qtd) {
    ll b = max(0ll,qtd*nb - ib);
    ll s = max(0ll,qtd*ns - is);
    ll c = max(0ll,qtd*nc - ic);

    return(pb*b + ps*s + pc*c <= cash);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'B') nb++;
        else if(s[i] == 'S') ns++;
        else nc++;
    }

    cin >> ib >> is >> ic;
    cin >> pb >> ps >> pc;
    cin >> cash;

    ll l = 0;
    ll r = 2e12;
    ll ans = 0;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        if(check(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }

    cout << ans << endl;

    return 0;
}

