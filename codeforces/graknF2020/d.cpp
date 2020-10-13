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
typedef vector<ii> vii;
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e6+3;
int n,m,a, b = T;

vti ve;
vii q;
int v[T+5], seg[4*T+5];

void build(int node, int i, int j) {
    if(i==j) {
        seg[node] = v[i];
    } else {
        int mid = (i+j)>>1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        seg[node] = max(seg[2*node],seg[2*node+1]);
    }
}

int query(int node, int i, int j) {
    if(i > b or j < a) return -1;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j)>>1;
    return max(query(2*node,i,mid),query(2*node+1,mid+1,j));
}

int solve(int t) {
    int ans = 0;
    for(ii tmp : q) {
        int x,y;
        tie(x,y) = tmp;
        a = x+t;
        int maxH = query(1,0,T);
        int aux = max(0, maxH-y+1);
        ans = max(ans,aux);
    }
    return ans;
}

int f(int mid) {
    if(mid<0) return INF;
    return mid+solve(mid);
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(v,-1,sizeof v);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x,y; cin >> x >> y;
        q.eb(x,y);
        ve.eb(y,x,0);
    }

    for(int i = 0; i < m; i++) {
        int x,y; cin >> x >> y;
        v[x] = max(v[x],y);
        ve.eb(y,x,1);
    }

    build(1,0,T);

    sort(ve.begin(), ve.end());
    int minx = INF;
    int ans = INF;

    for(int i = 0; i < ve.size(); i++) {
        int y,x,t;
        tie(y,x,t) = ve[i];
        if(!t) minx = min(minx,x);
        else ans = min(ans,f(x-minx+1));
    }
    cout << ans << endl;
    return 0;
}

