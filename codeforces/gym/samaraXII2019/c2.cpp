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

const ll T = 1e7;
bitset<T> ok;
ll p,n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> p >> n;
    n = min(n,p);
    ll at = 0;

    for(ll i = 0; i <= n; i++) {
        ok[at] = 1;
        at += (i+1ll);
        at %= p;
    }

    cout << ok.count() << endl;

    return 0;
}
