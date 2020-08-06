#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 5e5 + 3;
int seg[4*T];
int n,a,b;
char c;
string s;

void build(int node, int i, int j) {
    if(i == j) seg[node] = (1<<(s[i]-'a'));
    else {
        int mid = (i+j)>>1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        seg[node] = (seg[2*node] | seg[2*node+1]);
    }
}

void update(int node, int i, int j) {
    if(i > b or j < a) return;
    if(i >= a and j <= b) seg[node] = (1<<(c-'a'));
    else {
        int mid = (i+j)>>1;
        update(2*node,i,mid);
        update(2*node+1,mid+1,j);
        seg[node] = (seg[2*node] | seg[2*node+1]);
    }
}

int query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j)>>1;
    return (query(2*node,i,mid) | query(2*node+1,mid+1,j));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    s = "#" + s;
    build(1,1,n);
    int q; cin >> q;
    while(q--) {
        int op;
        cin >> op;
        if(op==1) {
            cin >> a >> c;
            b = a;
            update(1,1,n);
        } else {
            cin >> a >> b;
            cout << __builtin_popcount(query(1,1,n)) << endl;
        }
    }
    return 0;
}

