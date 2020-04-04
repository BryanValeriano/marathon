#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb  push_back
#define eb  emplace_back
#define mk  make_pair
#define fi  first
#define se  second
#define endl    '\n'

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 3e5 + 4;
const ll MOD = 1e9 + 7;

ll seg[4*T];
map<ll,int> bag;
ll v[T];
ll val;
int a,b;
int n;

void update(int node, int i, int j) {
    if(i > b or j < a) return;
    if(i == a and j == b) seg[node] = val;
    else {
        int mid = (i+j) >> 1;
        update(2*node,i,mid);
        update(2*node+1,mid+1,j);
        seg[node] = (seg[2*node] + seg[2*node+1]) % MOD;
    }
}

ll query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j) >> 1;
    return (query(2*node,i,mid) + query(2*node+1,mid+1,j)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    bag[0] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        bag[v[i]-v[i-1]] = 1;
        v[i] += v[i-1];
        bag[v[i]] = 1;
    }

    ll aux = 0;
    for(map<ll,int>::iterator it = bag.begin(); it != bag.end(); ++it)
        it->se = aux++;

    int zero = bag[0];
    int maxi = aux;
    cout << zero << " | " << maxi << endl;

    for(int i = 1; i <= n; i++) {
        int pos = bag[v[i]];

        if(bag[v[i]-v[i-1]] >= zero) {
            a = bag[v[i]-v[i-1]], b = maxi;
            val = max(1ll,query(1,0,maxi));
            a = b = pos;
            update(1,0,maxi);
        }
        for(int j = zero; j <= maxi; j++) {
            a = b = j;
            cout << query(1,0,maxi) << " ";
        }
        cout << endl;
    }


    a = zero, b = maxi;
    cout << query(1,0,n) << endl;

    return 0;
}
