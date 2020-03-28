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
const ll INI = 1152921504606846976ll;

int main() {
    ios_base::sync_with_stdio(false);
    ll l,r; cin >> l >> r;
    ll tmp = 0;
    for(ll i = INI; i > 0; i >>= 1) if((tmp|i) <= r) tmp |= i;
    cout << tmp << endl;
    cout << (l^tmp) << endl;

    return 0;
}

