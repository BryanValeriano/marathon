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

map<ii,vii> listas;
int x,y;
const int T = 1e6+3;
int seg[4*T];
int a,b,val;

void build(int node, int i, int j) {
    if(i == j) seg[node] = 0;
    else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        seg[node] = 0;
    }
}

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

int query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return max(query(2*node,i,mid),query(2*node+1,mid+1,j));
}

int inc(auto lista) {
    map<int,int> id;
    vector<int> ve;
    for(auto x : lista) ve.pb(x.se);
    sort(ve.begin(),ve.end());
    ve.resize(unique(ve.begin(),ve.end()) - ve.begin());
    for(int i = 0; i < ve.size(); i++) id[ve[i]] = i+1;

    int n = ve.size();
    build(1,0,n);
    int ans = 0;

    for(auto x : lista) {
        int i = x.se;
        a = 0; b = id[i]-1;
        int best = query(1,0,n);
        ans = max(ans,best+1);
        a=b=id[i];
        val = best+1;
        update(1,0,n);
    }

    return ans;
}

int dist(int a, int b) { return abs(a-x)+abs(b-y); }

int main() {
    ios_base::sync_with_stdio(false);
    cin >> x >> y;
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int a,b,h; cin >> a >> b >> h;
        int co = b-y, ca = a-x;
        int gcd = __gcd(abs(co),abs(ca));
        co /= gcd;
        ca /= gcd;
        listas[mk(co,ca)].eb(dist(a,b),h);
    }

    int ans = 0;
    for(auto tmp : listas) {
        auto lista = tmp.se;
        sort(lista.begin(),lista.end());
        ans += inc(lista);
    }
    cout << ans << endl;

    return 0;
}
