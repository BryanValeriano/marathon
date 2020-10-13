#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 6e5+5;
ll health[T];
ll dmg[T];
ll cost[T];
ll lastD[T];
int last[T];
int point[T];

ii dfs(int at, int fim, ll d) {
    if(at >= fim) return mk(0,at);
    if(last[at]) {
        //cerr << 1 << " " << at << " " << cost[at] << " " << last[at] << endl;
        ii x = dfs(last[at],fim,dmg[last[at]-1]);
        cost[at] += x.fi+lastD[at]-d;
        last[at] = x.se;
        lastD[at] = d;
        //cerr << 2 << " " << at << " " << cost[at] << " " << last[at] << endl;
    } else {
        ii x = dfs(point[at],fim,dmg[point[at]-1]);
        cost[at] = x.fi+health[at]-(health[at-1]+d);
        last[at] = x.se;
        lastD[at] = d;
        //cerr << 0 << " " << at << " " << cost[at] << " " << last[at] << endl;
    }
    return mk(cost[at],last[at]);
}


int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> health[i] >> dmg[i];
            if(i) health[i] += health[i-1];
            last[i] = last[i+n] = 0;
            dmg[i+n] = dmg[i];
        }

        for(int i = n+1; i < 2*n+1; i++)
            health[i] = (health[i-n]-health[i-n-1])+health[i-1];

        point[2*n+1] = 2*n+1;
        for(int i = 2*n; i >= 1; i--)
            point[i] = (health[i]+dmg[i] >= health[i+1]? point[i+1] : i+1);

        ll ans = 2e18;

        for(int i = 1; i <= n; i++) {
            ans = min(ans,dfs(i,i+n,0).fi);
            //cerr << i << " = " << cost[i] << " " << last[i] << endl;
        }

        cout << ans << endl;
    }
    return 0;
}

