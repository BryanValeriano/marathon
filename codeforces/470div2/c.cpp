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
int n;
const int INF = 0x3f3f3f3f;
const int T = 1e5 + 5;
ll seg[4*T + 4];
ll lazy[4*T + 4];
ll neve[T];
ll temp[T];
ll acum[T];
ll rest[T];

void prop(int node, int i, int j) {
    seg[node] += (lazy[node] * (j-i+1));
    if(i != j) {
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }
    lazy[node] = 0;
    if(seg[node] < 0) seg[node] = 0; 
}

void update(int node, int i, int j, int a, int b, ll val) {
    prop(node, i, j);
    if(i > b or j < a) return;
    if(i >= a and j <= b) {
        lazy[node] += val;
        prop(node, i, j);
    } else {
        int meio = (i+j)>>1;
        update(2*node, i, meio, a, b, val);
        update(2*node+1, meio+1, j, a, b, val);
        seg[node] = max(0LL,seg[2*node]) + max(0LL,seg[2*node+1]);
        seg[node] = max(0LL, seg[node]);
    }
}

ll query(int node, int i, int j, int a, int b) {
    prop(node, i, j);
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int meio = (i + j) >> 1;
    return max(0LL,query(2*node, i, meio, a, b)) + max(0LL,query(2*node+1, meio + 1, j, a, b));
}

ll bin(ll pass, ll x) {
    int ini = 0;
    int fim = n-1;
    while(fim - ini > 1) {
        int meio = (ini+fim)>>1;
        if(acum[meio] - pass <= x) ini = meio;
        else if(acum[meio] - pass > x) fim = meio;
    }
    return ini;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> neve[i];
    cin >> temp[0];
    acum[0] = temp[0];
    for(int i = 1; i < n; i++) {
        cin >> temp[i];
        acum[i] = temp[i] + acum[i-1];
    }
    for(int i = 0; i < n; i++) {
        if(neve[i] == 0) continue;
        ll pass = (i - 1 < 0? 0 : acum[i-1]);
        ll cheio = bin(pass, neve[i]);
        if(i == 0 and cheio == 0 and temp[i] > neve[i]) {
            rest[i] += neve[i]; 
            continue;
        }
        update(1, 0, n-1, i, cheio, 1);
        ll sobra = max(0LL, neve[i] - (acum[cheio] - pass));
        rest[cheio+1] += max(0LL, min(temp[cheio+1], sobra));
    }
    for(int i = 0; i < n; i++) 
        cout << query(1, 0, n-1, i, i) * temp[i] + rest[i] << " ";
    cout << endl;
    return 0;
}

