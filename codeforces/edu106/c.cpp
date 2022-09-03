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
int n;

ll solve(ll qtd, ll m1, ll m2) {
    int tmp1 = qtd>>1;
    int tmp2 = qtd-tmp1;
    return (n-tmp1)*m2 + (n-tmp2)*m1;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        ll ans = LLONG_MAX;
        ll bag = 0;
        int min1 = INF;
        int min2 = INF;
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            if(i&1) min1 = min(min1,x);
            else min2 = min(min2,x);
            bag += x;
            if(i > 1) ans = min(ans, bag+solve(i,min1,min2));
        }
        cout << ans << endl;
    }
    return 0;
}

