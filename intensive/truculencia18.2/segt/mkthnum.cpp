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
const int T = 1e5 + 4;

vector<int> seg[4*T];
int v[T];
int a, b;

void build(int node, int i, int j) {
    if(i == j) seg[node].pb(v[i]);
    else {
        int mid = (i+j) >> 1;
        build(2*node, i, mid);
        build(2*node+1, mid+1, j);
        seg[node].resize(j-i+1);

        merge(seg[2*node].begin(), seg[2*node].end(), 
            seg[2*node+1].begin(), seg[2*node+1].end(),
            seg[node].begin());
    }
}

int query(int node, int i, int j, int x) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return upper_bound(seg[node].begin(), seg[node].end(), x) - seg[node].begin();
    int mid = (i+j) >> 1;
    return query(2*node, i, mid, x) + query(2*node+1, mid+1, j, x);
}

int main() {
    ios::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> v[i];
    build(1,1,n);
    int x, ans;
    for(int i = 0; i < q; i++) {
        cin >> a >> b >> x;
        int l = -INF;
        int r = INF;
        while(l <= r) {
            int mid = (l+r) >> 1;
            if(query(1,1,n,mid) >= x) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

