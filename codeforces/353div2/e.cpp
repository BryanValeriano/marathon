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
const int T = 1e5+2;
ll v[T], seg[4*T+1], sum[4*T+1];
ll mark[4*T+1];
int a,b,c;

void prop(int node, int i, int j) {
    if(mark[node]) {
        seg[node] = (j-i+1)*mark[node];
        if(i!=j) {
            mark[2*node] = mark[2*node+1] = mark[node];
            sum[2*node] = sum[2*node+1] = 0;
        }
    }
    else if(sum[node]) {
        seg[node] += (j-i+1)*sum[node];
        if(i!=j) {
            if(mark[2*node]) mark[2*node] += sum[node];
            else sum[2*node] += sum[node];
            if(mark[2*node+1]) mark[2*node+1] += sum[node];
            else sum[2*node+1] += sum[node];
        }
    }
    mark[node] = sum[node] = 0;
}

void update(int node, int i, int j) {
    prop(node,i,j);
    if(i > b or j < a) return;
    if(i >= a and j <= b) {
        mark[node] = (c==1);
        sum[node] += (c==2);
        prop(node,i,j);
    } else {
        int mid = (i+j)>>1;
        update(2*node,i,mid);
        update(2*node+1,mid+1,j);
        seg[node] = seg[2*node]+seg[2*node+1];
    }
}

ll query(int node, int i, int j) {
    prop(node,i,j);
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j)>>1;
    return query(2*node,i,mid) + query(2*node+1,mid+1,j);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 1; i < n; i++) cin >> v[i];
    ll ans = 0;
    for(int i = n-1; i >= 1; i--) {
        a = i+1;
        b = v[i];
        c = 1;
        update(1,1,n);
        b = n;
        ans += (ll)query(1,1,n);
        a = i+1;
        b = v[i];
        c = 2;
        update(1,1,n);
    }
    cout << ans << endl;
    return 0;
}

