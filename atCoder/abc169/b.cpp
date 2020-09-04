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
const ll MAX = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    ll ans = 1;
    while(n--) {
        ll x; cin >> x;
        if(!x) { ans = 0; break; }
        if(MAX/ans < x) ans = -1;
        if(ans != -1) ans *= x;
    }
    cout << (ans>MAX?-1:ans) << endl;
    return 0;
}

