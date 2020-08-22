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
const int T = 100;
int a[T], b[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int c = INF, o = INF;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            c = min(c,a[i]);
        }
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            o = min(o,b[i]);
        }

        ll ans = 0;
        for(int i = 0; i < n; i++) ans += (ll)max(a[i]-c,b[i]-o);
        cout << ans << endl;
    }
    return 0;
}

