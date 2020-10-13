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
const int T = 3e5+5;
int a,b;
vector<vector<ll>> seg(4*T,vector<ll>(4));
ll v[T];

void build(int node, int i, int j) {
    if(i==j) seg[node] = {v[i],0,0,-v[i]};
    else {
        int mid = (i+j)>>1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        const vector<ll> &l = seg[2*node];
        const vector<ll> &r = seg[2*node+1];
        seg[node] = {max(l[0]+r[2],l[1]+r[0]),
                     max(l[0]+r[3],l[1]+r[1]),
                     max(l[2]+r[2],l[3]+r[0]),
                     max(l[2]+r[3],l[3]+r[1])};
    }
}

void update(int node, int i, int j) {
    if(i >= a and j <= b) seg[node] = {v[i],0,0,-v[i]};
    else {
        int mid = (i+j)>>1;
        if(a <= mid) update(2*node,i,mid);
        else update(2*node+1,mid+1,j);
        const vector<ll> &l = seg[2*node];
        const vector<ll> &r = seg[2*node+1];
        seg[node] = {max(l[0]+r[2],l[1]+r[0]),
                     max(l[0]+r[3],l[1]+r[1]),
                     max(l[2]+r[2],l[3]+r[0]),
                     max(l[2]+r[3],l[3]+r[1])};
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin >> tc;

    while(tc--) {
        int n,q;
        cin >> n >> q;
        for(int i = 0; i < n; i++) cin >> v[i];
        build(1,0,n-1);
        cout << max(seg[1][0],seg[1][1]) << endl;
        while(q--) {
            int l,r; cin >> l >> r;
            l--;r--;
            swap(v[l],v[r]);
            a = b = l; update(1,0,n-1);
            a = b = r; update(1,0,n-1);
            cout << max(seg[1][0],seg[1][1]) << endl;
        }
    }
    return 0;
}

