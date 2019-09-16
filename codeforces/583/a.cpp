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
const int inf = 0x3f3f3f3f;
const double pi = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    ll r,d,e;
    cin >> r >> d >> e;
    e *= 5;

    ll ans = r;

    for(ll i = 0; i*d <= r; i++) {
        ll dol = i*d;
        ll left = (r - i*d) % e;
        ans = min(ans,left);
    }

    cout << ans << endl;

    return 0;
}

