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

const int T = 2e5 + 5;
ll need[T];
ll fr[T];

map<ii,int> promo;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        cin >> need[i];
        ans += need[i];
    }

    int q; cin >> q;
    while(q--) {
        int s,t,u;
        cin >> s >> t >> u;

        if(promo.count(mk(s,t))) {
            int uu = promo[mk(s,t)];
            if(uu!= 0) {
                fr[uu]--;
                if(fr[uu] < need[uu]) ans++;
            }
        }

        fr[u]++;
        if(fr[u] <= need[u]) ans--;
        promo[mk(s,t)] = u;

        cout << ans << endl;
    }

    return 0;
}

