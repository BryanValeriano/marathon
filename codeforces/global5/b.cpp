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

const int T = 3e5 + 5;
int pos[T];
ll seg[4*T];
ll lazy[4*T];
int n,a,b;

void prop(int node, int i, int j) {
    if(!lazy[node]) return;
    seg[node] += (ll)(j-i+1)*lazy[node];

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
        lazy[node]++;
        prop(node,i,j);
    } else {
        int mid = (i+j) >> 1;
        update(2*node,i,mid);
        update(2*node+1,mid+1,j);
        seg[node] = seg[2*node], seg[2*node+1];
    }
}

ll query(int node, int i, int j) {
    prop(node,i,j);
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return query(2*node,i,mid) + query(2*node+1,mid+1,j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        pos[x] = i;
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        a = b = pos[x];
        if(i < pos[x] + query(1,1,n)) {
            ans++;
            a = 1;
            b = pos[x];
            update(1,1,n);
        }
    }

    cout << ans << endl;

    return 0;
}

