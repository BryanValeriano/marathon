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
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        ll x = 0;
        while(n--) {
            ll b,k; cin >> b >> k;
            ll i = 0;
            ll c = 1;
            while(c*b <= k) c *= b, i++;
            for(; i >= 0; i--) {
                ll d = k/c;
                if(d&1) x ^= c;
                k -= d*c;
                c /= b;
            }
        }
        cout << (x?1:2) << endl;
    }
    return 0;
}

