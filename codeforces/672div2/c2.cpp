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
        seg[node] = {max(seg[2*node][0]+seg[2*node+1][2],seg[2*node][1]+seg[2*node+1][0]),
                     max(seg[2*node][0]+seg[2*node+1][3],seg[2*node][1]+seg[2*node+1][1]),
                     max(seg[2*node][2]+seg[2*node+1][2],seg[2*node][3]+seg[2*node+1][0]),
                     max(seg[2*node][2]+seg[2*node+1][3],seg[2*node][3]+seg[2*node+1][1])};
    }
}

void update(int node, int i, int j) {
    if(i >= a and j <= b) seg[node] = {v[i],0,0,-v[i]};
    else {
        int mid = (i+j)>>1;
        if(a <= mid) update(2*node,i,mid);
        else update(2*node+1,mid+1,j);
        seg[node] = {max(seg[2*node][0]+seg[2*node+1][2],seg[2*node][1]+seg[2*node+1][0]),
                     max(seg[2*node][0]+seg[2*node+1][3],seg[2*node][1]+seg[2*node+1][1]),
                     max(seg[2*node][2]+seg[2*node+1][2],seg[2*node][3]+seg[2*node+1][0]),
                     max(seg[2*node][2]+seg[2*node+1][3],seg[2*node][3]+seg[2*node+1][1])};
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int tc; cin >> tc;
    build(1,0,T-1);

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

