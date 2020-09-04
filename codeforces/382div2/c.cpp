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
const int N = 100;
const ll T = 2e18;
ll fib[N];

int main() {
    ios_base::sync_with_stdio(false);
    fib[1] = 2;
    fib[2] = 3;
    int lim;
    for(lim = 3; T-fib[lim-1] > fib[lim-2]; lim++)
        fib[lim] = (fib[lim-1]+fib[lim-2]);

    ll n; cin >> n;
    int ans;

    for(ans = 1; ans < lim; ans++) {
        if(fib[ans] > n) {
            cout << ans-1 << endl;
            return 0;
        }
    }

    return 0;
}

