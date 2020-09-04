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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e5+10;
int seg[4*T+10];
map<int,int> id;
vii v;
int a,b,val;

void update(int node, int i, int j) {
    if(i > b or j < a) return;
    if(i >= a and j <= b) seg[node] = max(seg[node],val);
    else {
        int mid = (i+j)>>1;
        update(2*node,i,mid);
        update(2*node+1,mid+1,j);
        seg[node] = max(seg[2*node],seg[2*node+1]);
    }
}

int query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j)>>1;
    return max(query(2*node,i,mid),query(2*node+1,mid+1,j));
}

bool isIn(int ok, int x1, int x2) {
    return (ok >= min(x1,x2) and ok <= max(x1,x2));
}

bool cmp(ii &x, ii &y) {
    if(x.fi != y.fi) return x.fi > y.fi;
    return x.se < y.se;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    id[y1] = 1;
    id[y2] = 1;

    if(y1 > y2) {
        swap(x1,x2);
        swap(y1,y2);
    }

    for(int i = 0; i < n; i++) {
        int x,y; cin >> x >> y;
        v.eb(x,y);
        id[y] = 1;
    }

    int last = 1;
    vii tmp;
    for(ii x : id) tmp.eb(x.fi,last++);
    for(ii x : tmp) id[x.fi] = x.se;

    if(x1 <= x2) sort(v.begin(),v.end());
    else sort(v.begin(),v.end(),cmp);

    for(int i = 0; i < n; i++) {
        if(isIn(v[i].fi,x1,x2)) {
            int pos = id[v[i].se];
            a = id[y1], b = pos;
            if(a > b) continue;
            val = query(1,1,T-1);
            val++;
            a = b = pos;
            update(1,1,T-1);
        }
    }

    a = id[y1]; b = id[y2];
    cout << query(1,1,T-1) << endl;
    return 0;
}

