#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 1024000 + 3;
ll seg[4*T + 1];
ll lazy[4*T + 1];
string row;
int a, b;
 
void build(int node, int i, int j) {
    if(i == j) {seg[node] = row[i] - '0'; cout << seg[node]; }
    else {
        int meio = (i + j) >> 1;
        build(2*node, i, meio);
        build(2*node+1, meio + 1, j);
        seg[node] += seg[2*node] + seg[2*node + 1];
    }
}

void propaga(int node, int i, int j) {
    if(lazy[node] >= 1) seg[node] += lazy[node] * (j - i + 1);
    else if(lazy[node] == 0) seg[node] = lazy[node] * (j - i + 1);
    if(i != j) {
        int meio = (i + j) >> 1;
        propaga(2*node, i, meio);
        propaga(2*node+1, meio + 1, j);
    }
    lazy[node] = 0;
}

ll upquery(int node, int i, int j, int val, int val2) {
    propaga(node, i, j);
    if(i > b || j < a) return 0;
    if(i >= a && j <= b) {
        if(val2 != 1) {
            if(val2 != 2 && val == 0) lazy[node] = val;
            else if(val2 != 2 && val == 1) lazy[node] = val;
            else if(lazy[node] >= 1) lazy[node] = 0;
            else lazy[node] = 1;
        }
        propaga(node, i, j);
        return seg[node];
    } else {
        int meio = (i + j) >> 1;
        ll L = upquery(2*node, i, meio, val, val2);
        ll R = upquery(2*node+1, meio + 1, j, val, val2);
        return L + R;
    } 
}
    

int main() {
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        memset(seg, 0, sizeof seg);
        memset(lazy, -1, sizeof lazy);
        cout << "Case " << ++cont << ":" << endl; 
        row = "";
        int par; cin >> par;
        while(par--) {
            int mult; cin >> mult;
            string tmp; cin >> tmp;
            while((mult --) >= 1)row += tmp;
            //cout << row << endl;
        }
        int tam = row.length();
        build(1, 0, tam -1); 
        int q; cin >> q;
        int aux = 0;
        while(q--) {
            char op;
            cin >> op >> a >> b;
            if(op == 'F') upquery(1, 0, tam-1, 1, 0);
            else if(op == 'B') upquery(1, 0, tam-1, 0, 0);
            else if(op == 'I') upquery(1, 0, tam-1, 0, 2); 
            else if(op == 'S') cout << "Q" << ++aux << ": " << upquery(1, a, b, 0, 1) << endl; 
        }
    }
    return 0;
}

