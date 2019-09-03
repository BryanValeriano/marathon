#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector< pair<int,int> > vii;
typedef vector< pair<ll,ll> >vll;
const int INF = 0x3f3f3f3f;
const int T = 2e5 + 10;
int seg[4*T];
vll v;
int n;
ll t;

void update(int node, int i, int j, int p, int val) {
    if(i > p or j < p) return;
    if(i >= p and j <= p) seg[node] = 1;
    else {
        int mid = (i+j)>>1;
        update(2*node, i, mid, p, val);
        update(2*node+1, mid+1, j, p, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

int query(int node, int i, int j, int a, int b) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j)>>1;
    return query(2*node, i, mid, a, b) + query(2*node+1, mid+1, j, a, b);
}


bool cmp(const pll &a, const pll &b) {
    return a.fi > b.fi;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> t;
    int aux;
    cin >> aux;
    v.eb(aux,0);
    for(int i = 1; i < n; i++) {
        cin >> aux;
        v.eb(aux+v[i-1].fi,i);
    }
    sort(v.begin(), v.end(), cmp);
    ll ans = 0;
    int point = 0;
    ll low;
    for(int i = 0; i < n; i++) {
        low = v[i].fi - t;
        while(point < n && v[point].fi > low) {
            update(1, 0, n-1, v[point].se, 1);
            point++;
        }
        if(v[i].fi < t) ans++; 
        ans += query(1, 0, n-1, 0, v[i].se - 1); 
    }
    cout << ans << endl;


    return 0;
}

