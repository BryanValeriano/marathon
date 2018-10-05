#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int TAM = 1e5 + 3;
int row[TAM];
int row2[TAM];
ll seg[4*TAM + 4];
ll seg2[4*TAM + 4];
int flag, a, b;

void build(int node, int i, int j, int aux) {
    if(i == j) {
        if(aux == 1) seg[node] = row[i]; 
        else  seg2[node] = row2[i]; 
    } else {
        int meio = (i + j) >> 1;
        build(2*node, i, meio, aux);
        build(2*node+1, meio + 1, j, aux);
        if(aux == 1) seg[node] = seg[2*node] + seg[2*node+1];
        else seg2[node] = seg2[2*node] + seg2[2*node+1];
    }
}

ll query(int node, int i, int j) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) {
        if(flag == 1)  return seg[node];
        else return seg2[node];
    } else {
        int meio = (i + j) >> 1;
        return ( query(2*node, i, meio) + query(2*node + 1, meio + 1, j) );
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> row[i];
        row2[i] = row[i];
    }
    sort(row2, row2 + n);
    build(1, 0, n-1, 1);
    build(1, 0, n-1, 2);
    
    int q; cin >> q;
    while(q--) {
        cin >> flag >> a >> b;
        a--; b--;
        cout << query(1, 0, n-1) << endl;
    }
    return 0;
}

