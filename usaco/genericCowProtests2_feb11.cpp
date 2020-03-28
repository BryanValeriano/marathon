#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb  push_back
#define eb  emplace_back
#define mk  make_pair
#define fi  first
#define se  second
#define endl    '\n'

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5 + 4;
const ll MOD = 1e9 + 7;

ll seg[4*T];
bool isLeft[T];
bool foi[T];
ll vis[T];
ll v[T];
ll val;
int a,b;
vii p;
int n;

void update(int node, int i, int j) {
    if(i > b or j < a) return;
    if(i == a and j == b) seg[node] = val;
    else {
        int mid = (i+j) >> 1;
        update(2*node,i,mid);
        update(2*node+1,mid+1,j);
        seg[node] = (seg[2*node] + seg[2*node+1]) % MOD;
    }
}

ll query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return (query(2*node,i,mid) + query(2*node+1,mid+1,j)) % MOD;
}

bool sum(int x, int y) {
    return v[y]-v[x] >= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
        p.eb(v[i],i);
        vis[i] = 1;
    }
    sort(p.begin(), p.end());

    for(int i = 1; i <= n; i++)
        if(sum(0,i) and sum(i,n)) isLeft[i] = 1;

    int point = 0;
    ll ans = 0;

    point = 0;
    for(auto pi : p) {
        int up = pi.fi;
        if(!isLeft[pi.se]) continue;

        while(point < n and p[point].fi <= up) {
            if(isLeft[p[point].se]) {
                a = b = p[point].se, val = vis[a];
                update(1,0,n);
                foi[a] = 1;
            }
            point++;
        }

        b = pi.se;
        a = 0;
        ll canBeRight = query(1,0,n);

        //cout << " ans " << pi.se << " " << canBeRight << endl;
        //for(int i = 0; i <= n; i++) {
        //    a = b = i;
        //    cout << query(1,0,n) << " ";
        //}
        //cout << endl;

        if(pi.se == n) { ans = canBeRight; break; }
        if(foi[pi.se]) {
            val = canBeRight;
            a = b = pi.se;
            update(1,0,n);
        } else vis[pi.se] = canBeRight;
    }

    cout << ans << endl;
    return 0;
}
