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
const int T = 2e5 + 10;
int a[T];
int b[T];
int seg[4*T];

void build(int node, int i, int j) {
    if(i == j) seg[node] = (a[i] == b[i]);
    else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    build(1, 1, n);
    int oper,la,ra,lb,rb;
    for(int i = 0; i < m; i++) {
        cin >> oper;
        if(oper == 1) {
            cin >> la >> ra



    return 0;
}

