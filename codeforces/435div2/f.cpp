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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 10;
string v[T];
ll ve[T];
ll seg[4*T];
vii nR[4*T];
vii nL[4*T];
ll a,b;
int n;

ll lcp(int x, int y, int w, int z) {
    for(int i = 0; i < min(x,y); i++)
        if(v[w][i] != v[z][i]) return i;
    return min(x,y);
}

void buildCord(int node, int ii, int jj) {
    int x = ve[ii];
    int i = ii;
    while(i < n) {
        int j = i;
        while(j < n and ve[j] >= x) j++;
        nR[node].eb(x,j-i+1);
        i = j;
        x = ve[j];
    }

    x = ve[jj];
    i = jj;
    while(i > 0) {
        int j = i;
        while(j > 0 and ve[j] >= x) j--;
        nL[node].eb(x,i-j+1);
        i = j;
        x = ve[j];
    }
}

ll twoP(int node, ll i, ll j, int bordaI, int bordaJ) {
    //int l = (i+j) >> 1;
    //ll r = l+1;
    //ll ans = 0;
    //while(l >= bordaI and r <= bordaJ) {
    //    ll x = min(ve[l],ve[r]);

    //    r = min(bordaJ, nR[r]-1);
    //    l = max(bordaI, nL[l]+1);
    //    ans = max(ans,x*(r-l+2));

    //    if(r + 1 > bordaJ)  {
    //        if(l - 1 < bordaI) break;
    //        else l--;
    //    } else {
    //        if(l - 1 < bordaI) r++;
    //        else {
    //            r += (ve[r+1] >= ve[l-1]);
    //            l += (ve[l-1] > ve[r+1]);
    //        }
    //    }
    //}

    //return ans;
}

void build(int node, ll i, ll j) {
    if(i == j) seg[node] = max({ve[i]*2,(ll)v[i].size(),(ll)v[i+1].size()});
    else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        ll y = twoP(node,i,j,i,j);
        seg[node] = max({y, seg[2*node], seg[2*node+1]});
    }
}

void update(int node, ll i, ll j) {
    if(i > b or j < a) return;
    if(i >= a and j <= b) seg[node] = max({ve[i]*2,(ll)v[i].size(),(ll)v[i+1].size()});
    else {
        int mid = (i+j) >> 1;
        update(2*node,i,mid);
        update(2*node+1,mid+1,j);
        ll y = twoP(node,i,j,i,j);
        seg[node] = max({y, seg[2*node], seg[2*node+1]});
    }
}

ll query(int node, ll i, ll j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    ll w = query(2*node,i,mid);
    ll z = query(2*node+1,mid+1,j);
    ll y = twoP(node,i,j,a,b);
    return max({w,z,y});
}

int main() {
    ios_base::sync_with_stdio(false);
    int q,op; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i < n; i++) ve[i] = lcp(v[i].size(),v[i+1].size(),i,i+1);
    build(1,1,n-1);

    while(q--) {
        cin >> op >> a;
        if(op == 1) {
            cin >> b;
            if(a == b) cout << v[a].size() << endl;
            else b--, cout << query(1,1,n-1) << endl;
        } else {
            cin >> v[a];
            ve[a] = lcp(v[a].size(), v[a+1].size(), a,a+1);
            b = a;
            update(1,1,n-1);
            if(ve[a] < ve[a-1])
            if(a > 1) {
                ve[a-1] = lcp(v[a-1].size(), v[a].size(), a-1,a);
                b--; a--;
                update(1,1,n-1);
            }
        }
    }

    return 0;
}

