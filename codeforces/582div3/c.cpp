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

ll v[11];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        ll n,m;
        cin >> n >> m;
        ll tot = n/m;

        for(ll i = 1; i <= 10; i++) v[i] = (m*i) % 10;
        for(int i = 1; i <= 10; i++) v[i] += v[i-1];

        ll rest = tot % 10;
        ll ans = (tot/10) * v[10];

        ans += v[rest];

        cout << ans << endl;
    }

    return 0;
}

