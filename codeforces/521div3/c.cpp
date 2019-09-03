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
const int T = 2e5 + 3;
int v[T];
ll seg[4*T];

void build(int node, int i, int j) {
    if(i == j) seg[node] = v[i];
    else {
        int meio = (i+j)>>1;
        build(2*node, i, meio);
        build(2*node+1, meio+1, j);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

void update(int node, int i, int j, int p, int val) {
    if(i > p or j < p) return;
    if(i >= p and j <= p) seg[node] = val;
    else {
        int meio = (i+j)>>1;
        update(2*node, i, meio, p, val);
        update(2*node+1, meio+1, j, p, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll>ans;
    map<ll,ll>ind;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        ind[v[i]]++;
    }
    build(1, 0, n-1);
    for(int i = 0; i < n; i++) {
        ll x = v[i];
        update(1, 0, n-1, i, 0);
        if(seg[1] % 2 == 0 and ind.count(seg[1]/2) and (x != seg[1]/2 or ind[seg[1]/2] != 1))
            ans.pb(i+1);
        //cout << seg[1]/2 << endl;
        update(1, 0, n-1, i, x);
    }
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

