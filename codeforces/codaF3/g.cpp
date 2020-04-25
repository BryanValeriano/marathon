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

int main() {
    ios_base::sync_with_stdio(false);
    ll height, n;
    cin >> height >> n;

    ll id = (1ll << height) + (n-1);
    ll h = 1, ans = 0;
    bool corn = (id&1);

    while(id/2 != 1ll) {
        ll father = id/2;
        ans += ((father&1) == (id&1)? (1ll << h) : 1);
        id = father;
        corn = id&1;
        h++;
    }

    ans += (corn? (1ll << height) : 1);
    cout << ans << endl;

    return 0;
}

