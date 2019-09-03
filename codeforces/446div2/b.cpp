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
const int T = 1e6 + 4;
ll seg[4*T+1];
ll lazy[4*T+1];

void prop(int node, int i, int j) {
    seg[node] = (lazy[node] * (j-i+1) > 0? lazy[node] * (j-i+1) : seg[node]);
    if(i != j) {
        lazy[2*node] = (lazy[node] > 0? lazy[node] : lazy[2*node]);
        lazy[2*node+1] = (lazy[node] > 0? lazy[node] : lazy[2*node]);
 
    }
    lazy[node] = 0;
}

void update(int node, int i, int j, int a, int b, int val) {
    prop(node, i, j);
    if(i > b or j < a) return;
    if(i >= a and j <= b) {
        lazy[node] = val;
        prop(node, i, j);
    } else {
        int meio = (i+j) >> 1;
        update(2*node, i, meio, a, b, val);
        update(2*node + 1, meio + 1, j, a, b, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}


int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int row[n];
    for(int i = 0; i < n; i++)
        cin >> row[i];
    for(int i = n-1; i > 0; i--) {
        int tam = row[i];
        int ini = max(0, i - tam);
        int fim = max(0, i-1);
        if(row[i] != 0) update(1, 0, n-1, ini, fim, 1); 
        
    }
    prop(1, 0, n-1);
    ll sum = seg[1];
    
    cout << (n - sum) << endl;
    return 0;
}

