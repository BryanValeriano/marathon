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
const int T = 3e4 + 10;
vector<int> seg[4*T];
int v[T];
int a, b, k;

void build(int node, int i, int j) {
    seg[node].resize(j-i+1);
    if(i == j) seg[node][0] = v[i];
    else {
        int mid = (i+j)>>1;
        build(2*node, i, mid);
        build(2*node+1, mid+1, j);
        merge(seg[2*node].begin(), seg[2*node].end(), seg[2*node+1].begin(), seg[2*node+1].end(), seg[node].begin());
    }
}

int query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) {
        return seg[node].end() - upper_bound(seg[node].begin(), seg[node].end(), k);
    }
    int mid = (i+j) >> 1;
    return query(2*node, i, mid) + query(2*node+1, mid+1, j);
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n; 
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    build(1,1,n); 
    int q; cin >> q;
    int lastAns = 0;
    int ans;
    while(q--) {
        cin >> a >> b >> k;
        a ^= lastAns;
        b ^= lastAns;
        k ^= lastAns;
        lastAns = query(1,1,n);
        cout << lastAns << endl;
    }
    return 0;
}

