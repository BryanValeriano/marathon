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
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e9+1;
const int N = 1e7+5e6;
int l[N], r[N], seg[N];
int lazy[N];
int a,b,nodes;

void push(int node, ll i, ll j) {
    lazy[node]++;
    seg[node] = (j-i+1)-(ll)seg[node];
}

void prop(int node, int i, int j, int mid) {
    if(lazy[node]&1) {
        push(l[node],i,mid);
        push(r[node],mid+1,j);
    }
    lazy[node] = 0;
}

void update(int node, ll i, ll j) {
    if(i >= a and j <= b) push(node,i,j);
    else {
        ll mid = (i+j)>>1;
        if(!l[node]) l[node] = ++nodes, r[node] = ++nodes;
        prop(node,i,j,mid);
        if(mid >= a) update(l[node],i,mid);
        if(mid < b) update(r[node],mid+1,j);
        seg[node] = seg[l[node]] + seg[r[node]];
    }
}

int query(int node, ll i, ll j) {
    if(i >= a and j <= b) return seg[node];
    else {
        ll mid = (i+j)>>1;
        if(!l[node]) l[node] = ++nodes, r[node] = ++nodes;
        prop(node,i,j,mid);
        int ans = 0;
        if(mid >= a) ans += query(l[node],i,mid);
        if(mid < b) ans += query(r[node],mid+1,j);
        return ans;
    }
}

void proc(vector<int> &bag, int n) {
    for(int i = 1; i < bag.size(); i += 2) {
        b = bag[i];
        a = bag[i-1]+1;
        update(1,1,n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    vti v;
    int p,n;
    cin >> p >> n;

    for(int i = 1; i <= p; i++) {
        int x,y; cin >> x >> y;
        v.eb(x,i,y+T);
    }

    for(int i = 0; i < n; i++) {
        int x,y; cin >> x >> y;
        v.eb(x,0,y+T);
    }

    sort(v.begin(),v.end());
    ll ans = 0;
    int lx = -INF;
    vector<int> bag;
    n = 2e9+2;

    for(ti point : v) {
        int x,y,t;
        tie(x,t,y) = point;
        if(x != lx or t) proc(bag,n), bag.clear();
        if(!t) bag.pb(y);
        else {
            a = b = y;
            ans += (query(1,1,n)? 0 : t);
            int s = query(1,1,n);
        }
        lx = x;
    }

    cout << ans << endl;

    return 0;
}
