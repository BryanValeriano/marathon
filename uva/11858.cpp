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
const int T = 1e6 + 5;
int seg[4*T];
int v, a, b;
vector<ll> ve;
vector<ll> v2;
map<ll,int> id;

void update(int node, int i, int j) {
    if(i > b or j < a) return;
    if(i >= a and j <= b) seg[node] += v;
    else {
        int mid = (i+j) >> 1;
        update(2*node,i,mid);
        update(2*node+1,mid+1,j);
        seg[node] = (seg[2*node] + seg[2*node+1]);
    }
}

int query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return query(2*node,i,mid) + query(2*node+1,mid+1,j);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while(cin >> n) {
        ll ans = 0;

        for(int i = 0; i < n; i++) {
            ll x; cin >> x;
            ve.pb(x);
            v2.pb(x);
        }

        sort(v2.begin(), v2.end());
        for(int i = 0; i < v2.size(); i++) id[v2[i]] = i+1;

        v = 1;
        for(auto x : ve) {
            x = id[x];
            a = x, b = n;
            ans += (ll)query(1,0,n);
            a = b = x;
            update(1,0,n);
        }

        v = -1;
        for(auto x : ve) {
            a = b = id[x];
            update(1,0,n);
        }

        ve.clear();
        v2.clear();
        id.clear();

        cout << ans << endl;
    }

    return 0;
}

