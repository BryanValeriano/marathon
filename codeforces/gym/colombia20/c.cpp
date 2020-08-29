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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e3+3;
const int mod = 1000000007;

ll xp(ll b, ll e) {
    if (e == 0) return 1;
    ll c = xp(b, e >> 1);
    c *= c;
    c %= mod;
    if (e & 1) c *= b, c %= mod;
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);

    int a, k;
    cin >> a >> k;
    cout << xp(a, k) << endl;
    return 0;
}

