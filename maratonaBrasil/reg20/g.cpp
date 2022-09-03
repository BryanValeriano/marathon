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

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    ll ans = 0;
    ll sum = 0;
    while(n--) {
        ll x; cin >> x;
        sum += x;
        ans = max(ans,sum);
    }
    cout << ans+100 << endl;
    return 0;
}

