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

const int T = 2e5 + 10;
const int N = 1e6 + 10;
int v[T];
int a,b,x;
vector<int> seg[4*T];
vector<int> track[N];

void mer(int node) {
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
    if(i == j) seg[node].pb(v[i]);
    else {
        int mid = (i+j) >> 1;
        build(2*node, i, mid);
        build(2*node+1, mid+1, j);
        mer(node);
        seg[node].resize(unique(seg[node].begin(), seg[node].end()) - seg[node].begin());
    }
}

int query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) {
        for(int k = 0; k < seg[node].size(); k++) 
            if(seg[node][k] != x) return seg[node][k];
        return 0;
    } 
    int mid = (i+j) >> 1;
    return max(query(2*node, i, mid), query(2*node+1, mid+1, j));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        track[v[i]].pb(i);
    }

    build(1,1,n);
    while(q--) {
        cin >> a >> b >> x;
        int z =  query(1,1,n);
        if(!z) { cout << -1 << endl; continue; }
        int pos = lower_bound(track[z].begin(), track[z].end(), a) - track[z].begin(); 
        cout << track[z][pos] << endl;
    } 
    return 0;
}

