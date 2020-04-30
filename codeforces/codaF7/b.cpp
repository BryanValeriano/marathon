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
const int T = 1e5 + 3;
ll v[T];
double seg[4*T];
double lazy[4*T];
int a,b,n,q;
double val;

void prop(int node, int i, int j) {
    seg[node] += lazy[node]*(j-i+1);
    if(i != j) {
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int i, int j) {
    prop(node,i,j);
    if(i > b or j < a) return;
    if(i >= a and j <= b) {
        lazy[node] += val;
        prop(node,i,j);
        return;
    }
    int mid = (i+j)>>1;
    update(2*node,i,mid);
    update(2*node+1,mid+1,j);
    seg[node] = seg[2*node]+seg[2*node+1];
}

double query(int node, int i, int j) {
    prop(node,i,j);
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j)>>1;
    return query(2*node,i,mid)+query(2*node+1,mid+1,j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> v[i];
    while(q--) {
        cin >> a >> b >> val;
        update(1,1,n);
    }
    double ans = 0;
    for(int i = 1; i <= n; i++) {
        a = b = i;
        ans = max(ans,v[i]+query(1,1,n));
    }
    cout << fixed << setprecision(6)<<ans << endl;
    return 0;
}

