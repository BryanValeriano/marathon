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
ll b,p,l,a,v;
ll seg[4*T];
ll lazy[4*T];

ll exp(ll base, ll e) {
    ll ans = 1;
    ll ele = base;
    while(e) {
        if(e&1) ans = (ans * ele) % p;
        ele = (ele * ele) % p;
        e >>= 1;
    }
    return ans % p;
}

void prop(int node, int i, int j) {
    if(lazy[node] != -1) return;
    seg[node] = 0;
    if(i != j)
        lazy[2*node] = lazy[2*node+1] = lazy[node];
    lazy[node] = 0;
}

void update(int node, int i, int j) {
    prop(node, i, j);
    if(i > a or j < a) return;
        if(i >= a and j <= a) seg[node] = (v * exp(b,l-a)) % p;
    else {
        int mid = (i+j) >> 1;
        update(2*node, i, mid);
        update(2*node+1, mid+1, j);
        seg[node] = (seg[2*node] + seg[2*node+1]) % p;
    }
}

ll query(int node, int i, int j) {
    prop(node, i, j);
    if(i > v or j < a) return 0;
    if(i >= a and j <= v) return seg[node] % p;
    int mid = (i+j) >> 1;
    return (query(2*node, i, mid) + query(2*node+1, mid+1, j)) % p;
}

int main() {
    ios::sync_with_stdio(false);
    ll n;
    cin >> b >> p >> l >> n;
        while(b or p or l or n) {
        lazy[1] = -1;
        char oper;
        while(n--) {
            cin >> oper >> a >> v;
            if(oper == 'E') update(1,1,l);
            else {
                ll tmp = query(1,1,l);
                ll aux = exp(b,l-v);
                aux = exp(aux, p-2);
                cout << (tmp*aux) % p << endl;
            }
        }
        cin >> b >> p >> l >> n;
        cout << "-" << endl;
    }
    return 0;
}

