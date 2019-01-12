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
int seg[4*T];
int v[T];
int n, a, b;

void build(int node, int i, int j) {
    if(i == j) seg[node] = v[i];
    else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        seg[node] = min(seg[2*node], seg[2*node+1]);
    }
}

int query(int node, int i, int j) {
    if(i > b or j < a) return INF;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return min(query(2*node,i,mid), query(2*node+1,mid+1,j));
}

int main() {
    ios::sync_with_stdio(false);
    int tc, q; cin >> tc;
    int cont = 0;
    while(tc--) {
        cin >> n >> q;
        for(int i = 0; i < n; i++)
            cin >> v[i];
        build(1,0,n-1);
        cout << "Scenario #" << ++cont << ":" << endl;
        while(q--) {
            cin >> a >> b;
            a--; b--;
            cout << query(1,0,n-1) << endl;
        }
    }

    return 0;
}

