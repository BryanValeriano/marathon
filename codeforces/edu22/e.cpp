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

const int T = 1e5+ 3;

int v[T];
int qtd[T];
int n,k,a,b;
map<ii,int> track;

vector<int> seg[4*T];

void merge(int node) {
    int i = 0;
    int j = 0;
    int a = 2*node;
    int b = 2*node+1;
    
    while(i < seg[a].size() or j < seg[b].size()) {
        if(i < seg[a].size() and j < seg[b].size()) {
            if(seg[a][i] <= seg[b][j]) seg[node].pb(seg[a][i]), i++;
            else seg[node].pb(seg[b][j]), j++;
        } 
        else if(i < seg[a].size()) seg[node].pb(seg[a][i]), i++;
        else seg[node].pb(seg[b][j]), j++;
    }
}

void build(int node, int i, int j) {
    if(i == j) {
        if(v[i]) seg[node].pb(v[i]);
    } else {
        int mid = (i+j) >> 1;
        build(2*node, i, mid);
        build(2*node+1,mid+1,j);
        merge(node);
    }
}

int query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) {
        int x = lower_bound(seg[node].begin(), seg[node].end(), a) - seg[node].begin();
        return seg[node].size() - x;
    } 
    int mid = (i+j) >> 1;
    return query(2*node, i, mid) + query(2*node+1, mid+1,j);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int x;

    for(int i = 1; i <= n; i++) {
        cin >> x;
        qtd[x]++;
        if(qtd[x] > k) v[i] = track[ii(x,qtd[x]-k)];
        track[ii(x,qtd[x])] = i;
    }

    build(1,1,n);

    int q; cin >> q;
    int last = 0; 

    while(q--) {
        cin >> a >> b;
        a = ((a+last)%n)+1;
        b = ((b+last)%n)+1;
        if(a > b) swap(a,b);

        last = b-a+1 - query(1,1,n);
        cout << last << endl;
    }

    return 0;
}

