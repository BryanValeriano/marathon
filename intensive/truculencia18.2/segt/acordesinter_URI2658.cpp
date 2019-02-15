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
const int T = 1e5 + 10;
int a,b;

struct piano {
    int v[10];

    void monta(int x) {
        for(int i = 0; i < 9; i++) {
            if(i == x) v[i] = 1;
            else v[i] = 0;
        }
    }

    void add(int x) {
        piano xx;
        xx.monta(10);
        for(int i = 0; i < 9; i++) 
            xx.v[(i + x) % 9] = v[i];
        for(int i = 0; i < 9; i++) 
            v[i] = xx.v[i];
    }

    void merge(const piano &a, const piano &b) {
        for(int i = 0; i < 9; i++) v[i] = (a.v[i] + b.v[i]);
    }

    int fre() {
        int freq = 0;
        int val = 0;
        for(int i = 0; i < 9; i++)
            if(v[i] > freq or (v[i] == freq and i > val)) {
                freq = v[i];
                val = i;
            }
        return val;
    }
};

piano seg[4*T];
int lazy[4*T];

void prop(int node, int i, int j) {
    if(lazy[node] == 0) return;
    seg[node].add(lazy[node]);

    if(i != j) {
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }

    lazy[node] = 0;
}

void build(int node, int i, int j) {
    if(i == j) seg[node].monta(1);
    else {
        int mid = (i+j) >> 1;
        build(2*node, i, mid);
        build(2*node+1, mid+1,j);
        seg[node].monta(10); 
        seg[node].merge(seg[2*node], seg[2*node+1]);
    }
}

void update(int node, int i, int j, int val) {
    prop(node,i,j);
    if(i > b or j < a) return;
    if(i >= a and j <= b) {
        lazy[node] += val;
        prop(node, i, j);
    } else {
        int mid = (i+j) >> 1;
        update(2*node, i, mid, val);
        update(2*node+1, mid+1, j, val);
        seg[node].merge(seg[2*node], seg[2*node+1]);
    }
}

piano query(int node, int i, int j) {
    prop(node,i,j);
    if(i > b or j < a) {
        piano xx;
        xx.monta(10);
        return xx;
    }
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    piano xx;
    xx.merge(query(2*node,i,mid), query(2*node+1,mid+1,j));
    return xx;
}

int main() {
    ios::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    build(1,0,n-1);
    for(int i = 0; i < q; i++) {
        cin >> a >> b;
        piano x = query(1,0,n-1);
        update(1,0,n-1,x.fre());
    }
    for(int i = 0; i < n; i++) {
        a = b = i;
        piano x = query(1,0,n-1);
        cout << x.fre() << endl;
    }
    return 0;
}

