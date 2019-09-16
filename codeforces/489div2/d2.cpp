#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,ll> ii;
const ll INF = 0x3f3f3f3f3f3f3f;

const int T = 2e5 + 10;
const int SQR = sqrt(T)+2;

ll blk[SQR];
ll v[T];
ll acum[T];
ll dist[T];



void build() {
    for(int i = 0; i < SQR; i++) blk[i] = INF;
    for(int i = 1; i <= n; i++)
        blk[i/SQR] = min(abs(dist[i]),blk[i/SQR]);
}

void update(int a, int b, ll val) {
}

ii query(int node, int i, int j) {
    prop(node,i,j);
    if(i > b or j < a) return ii(INF, INF);
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return best(query(2*node, i, mid), query(2*node+1, mid+1, j));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,q; cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        acum[i] += v[i] + acum[i-1];
        dist[i] = v[i] - acum[i-1];
    }

    build(1,1,n);
    ll x,y;

    while(q--) {
        cin >> x >> y;

        val = y - v[x];
        v[x] = y;
        a = b = x;
        update(1,1,n);

        val = -val;
        a = x+1; b = n;
        if(a <= n) update(1,1,n);

        a = 1; b = n;
        ii ans = query(1,1,n);

        if(ans.fi == 0) cout << ans.se << endl;
        else cout << -1 << endl;
    }

    return 0;
}

