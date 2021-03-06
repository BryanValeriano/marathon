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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 3;
vector<ll> g[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int a,b; cin >> a >> b;
        if(a <= m) g[a].pb(b);
    }

    ll ans = 0;
    priority_queue<ll, vector<ll> > pq;

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j < g[i].size(); j++) pq.push(g[i][j]);
        if(pq.size()) ans += pq.top(), pq.pop();
    }
    cout << ans << endl;
    return 0;
}

