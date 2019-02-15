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
const int INF = 2e9;
const int T = 2e5 + 10;
int xx[T][2];
int seg[4*T][2];
int a,b,c;

void build(int node, int i, int j, int op) {
    if(i == j) seg[node][op] = xx[i][op];
    else {
        int mid = (i+j) >> 1;
        build(2*node, i, mid, op);
        build(2*node+1, mid+1, j, op);
        if(op == 0) seg[node][op] = max(seg[2*node][op], seg[2*node+1][op]);
        else seg[node][op] = min(seg[2*node][op], seg[2*node+1][op]);
    }
}

void update(int node, int i, int j, int op) {
    if(i > c or j < c) return;
    if(i >= c and j <= c) seg[node][op] = a;
    else {
        int mid = (i + j) >> 1;
        update(2*node, i, mid, op);
        update(2*node+1, mid+1, j, op); 
        if(op == 0) seg[node][op] = max(seg[2*node][op], seg[2*node+1][op]);
        else seg[node][op] = min(seg[2*node][op], seg[2*node+1][op]);
    }
}

int query(int node, int i, int j, int op) {
    if(i > b or j < a) {
        if(op == 0) return -INF;
        else return INF;
    }
    if(i >= a and j <= b) return seg[node][op];
    else { 
        int mid = (i+j) >> 1;
        int l = query(2*node, i, mid, op);
        int r = query(2*node+1, mid+1, j, op); 
        if(op == 0) return max(l,r);
        else return min(l,r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> xx[i][0] >> xx[i][1];
    build(1,1,n, 0);
    build(1,1,n, 1);
    char oper;

    for(int i = 0; i < q; i++) {
        cin >> oper;;
        if(oper == 'C') {
            cin >> c >> a >> b;
            update(1,1,n,0);
            a = b;
            update(1,1,n,1);
        } else {
            cin >> a >> b;
            cout << max(0, query(1,1,n,1) - query(1,1,n,0) + 1) << endl;
        }
    }
    return 0;
}

