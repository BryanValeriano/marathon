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
string s;
int q,a,b;
char c;

int bit(char z) {
    return (1 << (z-'a'));
}

void build(int node, int i, int j) {
    if(i == j) seg[node] = v[i];
    else {
        int mid = (i+j) >> 1;
        build(2*node,i,mid);
        build(2*node+1,mid+1,j);
        seg[node] = (seg[2*node] | seg[2*node+1]);
    }
}

void update(int node, int i, int j) {
    if(i > b or j < a) return;
    if(i >= a and j <= b) seg[node] = bit(c);
    else {
        int mid = (i+j) >> 1;
        update(2*node,i,mid);
        update(2*node+1,mid+1,j);
        seg[node] = (seg[2*node] | seg[2*node+1]);
    }
}

int query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return (query(2*node,i,mid) | query(2*node+1,mid+1,j));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s >> q;
    int n = s.size();

    for(int i = 0; i < n; i++) v[i] = bit(s[i]);
    build(1,0,n-1);
    int op;

    while(q--) {
        cin >> op;
        if(op == 2) { 
            cin >> a >> b;
            a--;b--;
            cout << __builtin_popcount(query(1,0,n-1)) << endl;
        } else {
            cin >> a >> c;
            b = a;
            a--; b--;
            update(1,0,n-1);
        }
    }   
    
    return 0;
}

