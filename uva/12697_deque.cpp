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
typedef pair<int,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

deque<ii> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n,m;
        cin >> n >> m;
        int ans = INF;
        ll aux = 0;
        dq.clear();
        for(int i = 0; i < n; i++) {
            ll x; cin >> x;
            while(!dq.empty() and dq.back().se+aux+x <= x) dq.pop_back();
            dq.eb(i,-aux);
            aux += x;
            while(!dq.empty() and dq.front().se+aux >= m) {
                ans = min(ans, i-dq.front().fi+1);
                dq.pop_front();
            }
        }
        cout << (ans==INF?-1:ans) << endl;
    }
    return 0;
}

