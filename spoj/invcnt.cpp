#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int t = 1e7 + 3;
ll seg[4*t+1];
ll row[t];

void update(int node, int i, int j, int p, int val) {
    if(i > p or j < p) return; 
    if(i >= p and j <= p) seg[node] += val;
    else {
        int meio = (i+j)>>1;
        update(2*node, i, meio, p, val);
        update(2*node+1, meio+1, j, p, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

int query(int node, int i, int j, int a, int b) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int meio = (i+j) >> 1;
    return query(2*node, i, meio, a, b) + query(2*node+1, meio+1, j, a, b);
}

int main()
{
    int tc; cin >> tc;
    while(tc--) {
        int n, aux; cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> row[i];
        }
        ll val = 0;
        n--;
        while(n >= 0) {
            val += query(1, 0, t, 0, row[n]-1);
            update(1, 0, t, row[n--], 1);
        }
        cout << val << endl; 
        memset(seg, 0, sizeof seg);
    }
    return 0;
}

