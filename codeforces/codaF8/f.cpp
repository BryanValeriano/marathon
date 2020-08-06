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
const int T = 302;
ll dist[T][T];
ll nd[T];
int vis[T];
int vez,n;

ll floyd(int a, int b, ll d) {
    ll ans = max(0ll, 2ll*(dist[a][b]-d));
    dist[a][b] = min(dist[a][b],d);
    dist[b][a] = min(dist[b][a],d);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            ll ok = min(dist[i][j],dist[i][a]+dist[a][b]+dist[b][j]);
            ok = min(ok, dist[i][b]+dist[b][a]+dist[a][j]);
            ans += max(0ll,(dist[i][j]-ok));
            dist[i][j] = ok;
        }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ll ans = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            cin >> dist[i][j];
            ans += dist[i][j];
        }

    int k; cin >> k;
    while(k--) {
        int a,b; ll d;
        cin >> a >> b >> d;
        ans -= floyd(a,b,d);
        cout << (ans>>1) << endl;
    }

    return 0;
}

