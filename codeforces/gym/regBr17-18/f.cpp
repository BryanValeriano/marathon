#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,ll> ii;
typedef tuple<ll,ll,ll> tl;
typedef vector<tl> vtl;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 3e5;
ll seg[4*T+10];
map<int,int> id;
map<ii,ll> uni;
vector<int> ve;
vtl bag;
int n,a,b;
ll val;

void update(int node, int i, int j) {
    if(i > b or j < a) return;
    if(i >= a and j <= b) seg[node] = max(val,seg[node]);
    else {
        int mid = (i+j) >> 1;
        update(2*node,i,mid);
        update(2*node+1,mid+1,j);
        seg[node] = max(seg[2*node],seg[2*node+1]);
    }
}

ll query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return max(query(2*node,i,mid),query(2*node+1,mid+1,j));
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x,y,z; cin >> x >> y >> z;
        ve.pb(y);
        ve.pb(y-1);
        uni[mk(x,y)] += z;
    }

    sort(ve.begin(), ve.end());
    ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
    for(int i = 0; i < ve.size(); i++) id[ve[i]] = i+1;
    for(auto ok : uni) bag.eb(ok.fi.fi,ok.fi.se,ok.se);

    ll ans = 0;
    ll last = get<0>(bag[0]);
    vector<ii> up;

    for(auto ok : bag) {
        ll x,y,z;
        tie(x,y,z) = ok;

        if(x != last) {
            for(auto nok : up) {
                a = b = nok.fi;
                val = nok.se;
                update(1,1,T-1);
                ans = max(ans,val);
            }
            up.clear();
        }

        last = x;
        a = 0;
        b = id[y-1];
        ll k = query(1,1,T-1);
        up.eb(id[y],k+z);
    }

    for(auto nok : up) {
        a = b = nok.fi;
        val = nok.se;
        update(1,1,T-1);
        ans = max(ans,val);
    }

    cout << ans << endl;
    return 0;
}

