#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 10;
int v[T];
ii seg[4*T];
int a,b;

ii best(ii a, ii b) {
    int x[4] = { a.fi, a.se, b.fi, b.se };
    sort(x, x+4);
    return ii(x[3], x[2]);
}

void build(int node, int i, int j) {
    if(i == j) seg[node] = mk(v[i],0);
    else {
        int mid = (i+j) >> 1;
        build(2*node, i, mid);
        build(2*node+1, mid+1, j);
        seg[node] = best(seg[2*node], seg[2*node+1]);
    }
}

void update(int node, int i, int j) {
    if(i > a or j < a) return;
    if(i >= a and j <= a) seg[node].fi = b; 
    else {
        int mid = (i+j) >> 1;
        update(2*node, i, mid);
        update(2*node+1, mid+1, j);
        seg[node] = best(seg[2*node], seg[2*node+1]);
    }
}

ii query(int node, int i, int j) {
    if(i > b or j < a) return mk(0,0);
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return best(query(2*node, i, mid), query(2*node+1, mid+1,j));
}

int main() {
    ios::sync_with_stdio(false);
    int n,q;
    char oper;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];
    build(1,1,n);
    cin >> q;
    while(q--) {
        cin >> oper >> a >> b;
        if(oper == 'U') update(1,1,n);
        else {
            ii ans = query(1,1,n);
            cout << ans.fi + ans.se << endl;
        }
    }
    return 0;
}

