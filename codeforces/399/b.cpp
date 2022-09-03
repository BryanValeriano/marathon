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
ll a,b;

ll aux(ll x) {
    if(x < 2) return 0;
    return (1ll << ((ll)log2(x) + 1))-1;
}

ll solve(ll n, ll l, ll r) {
    if(l > b or r < a) return 0;
    ll x = l + ((r-l+2)>>1) - 1;
    ll tmp = (x >= a && x <= b? n&1 : 0);
    return tmp + (n > 1? solve(n/2, l, x-1) + solve(n/2, x+1, r) : 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n >> a >> b;
    if(n < 2) {
        cout << n << endl;
        return 0;
    }
    cout << solve(n,1,aux(n)) << endl;
    return 0;
}

