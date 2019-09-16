#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int32_t main() {
    ios_base::sync_with_stdio(false);
    ll n,m,q;
    cin >> n >> m >> q;
    ll gcd = __gcd(n,m);
    ll um = n/gcd;
    ll dois = m/gcd;

    while(q--) {
        ll s1,s2,e1,e2;
        cin >> s1 >> s2 >> e1 >> e2;
        auto group = [&] (const ll g, ll c) {
            c--;
            return (g == 1? c/um : c/dois);
        };
        cout << (group(s1,s2) == group(e1,e2)? "YES" : "NO") << endl;
    }
    return 0;
}
