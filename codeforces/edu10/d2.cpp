#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 2*(2e5 + 10);
vector<int> inter[T];
vector<int> seg[4*T];
vii q;
vector<int> v;
map<int,int> ind;
int a, val;
int b = T-1;

void myM(int node) {
    int i = 0;
    int j = 0;
    while(i < seg[2*node].size() and j < seg[2*node+1].size()) {
        if(seg[2*node][i] <= seg[2*node+1][j]) seg[node].pb(seg[2*node][i]), i++;
        else seg[node].pb(seg[2*node+1][j]), j++;
    }
    while(i < seg[2*node].size()) seg[node].pb(seg[2*node][i]), i++;
    while(j < seg[2*node+1].size()) seg[node].pb(seg[2*node+1][j]), j++;
}

void build(int node, int i, int j) {
    if(i == j) seg[node] = inter[i];
    else {
        int mid = (i+j) >> 1;
        build(2*node, i, mid);
        build(2*node+1, mid+1, j);
        myM(node);
    }
}

int query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) {
        int low = lower_bound(seg[node].begin(), seg[node].end(), val) - seg[node].begin();
        return low;
    }
    int mid = (i+j) >> 1;
    return(query(2*node, i, mid) + query(2*node+1, mid+1,j));
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int x, y;

    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        v.pb(x);
        v.pb(y);
        q.pb({x,y});
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for(int i = 0; i < v.size(); i++) ind[v[i]] = i;

    for(int i = 0; i < n; i++) inter[ind[q[i].fi]].pb(ind[q[i].se]);
    for(int i = 0; i < T-1; i++) if(inter[i].size()) sort(inter[i].begin(), inter[i].end());

    build(1,0,T-1);

    for(int i = 0; i < n; i++) {
        a = ind[q[i].fi];
        val = ind[q[i].se];
        cout << query(1,0,T-1) << endl;
    }
    return 0;
}
