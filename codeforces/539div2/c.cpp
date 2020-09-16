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
const int T = (1<<20)+5;
vector<int> g[T];
ll tmp[2];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int xr = 0;


    g[0].pb(0);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        xr ^= x;
        g[xr].pb(i);
    }

    ll ans = 0;

    for(int i = 0; i < T; i++) {
        tmp[0] = tmp[1] = 0;
        for(int x : g[i]) {
            bool odd = (x&1);
            ans += tmp[odd];
            tmp[odd]++;
        }
    }
    cout << ans << endl;
}

