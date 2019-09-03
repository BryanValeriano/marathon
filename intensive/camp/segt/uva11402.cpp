#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 1024000 + 10;
int seg[4*T + 1];
int lazy[4*T + 1];
string row;
int a, b;
 
void build(int node, int i, int j) {
    if(i == j) seg[node] = row[i] - '0'; 
    else {
        int meio = (i + j) >> 1;
        build(2*node, i, meio);
        build(2*node+1, meio + 1, j);
        seg[node] += seg[2*node] + seg[2*node + 1];
    }
}

void preenche(int node) {
     if(lazy[node] == -3) {
        if(lazy[2*node] == -1) lazy[2*node] = -2;
        else if(lazy[2*node] == -2) lazy[2*node] = -1;
        else if(lazy[2*node] == -3) lazy[2*node] = -4;
        else lazy[2*node] = -3;
        if(lazy[2*node+1] == -1) lazy[2*node+1] = -2;
        else if(lazy[2*node+1] == -2) lazy[2*node+1] = -1;
        else if(lazy[2*node+1] == -3) lazy[2*node+1] = -4;
        else lazy[2*node+1] = -3;
    } 
    else if(lazy[node] == -4 and lazy[2*node] == -3) lazy[node] = -4;
    else if(lazy[node] != -4) lazy[2*node] = lazy[2*node+1] = lazy[node];
}

void propaga(int node, int i, int j) {
    if(lazy[node] == 0) return;
    if(lazy[node] == -1) seg[node] = (j-i+1);
    else if(lazy[node] == -2) seg[node] = 0;
    else if(lazy[node] == -3) seg[node] = (j-i+1) - seg[node];
    if(i != j) preenche(node);
    lazy[node] = 0;
}

void update(int node, int i, int j, int flag) {
    propaga(node, i, j);
    if(i > b or j < a) return;
    if(i >= a and j <= b) {
        lazy[node] = flag;
        propaga(node,i,j);
    } else {
        int meio = (i+j) >> 1;
        update(2*node, i, meio, flag);
        update(2*node+1, meio+1, j, flag);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

int query(int node, int i, int j) {
    propaga(node, i, j);
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int meio = (i+j) >> 1;
    return query(2*node, i,meio) + query(2*node+1, meio+1,j);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        memset(seg, 0, sizeof seg);
        memset(lazy, 0, sizeof lazy);
        cout << "Case " << ++cont << ":" << endl; 
        row = "";
        int par; cin >> par;
        while(par--) {
            int mult; cin >> mult;
            string tmp; cin >> tmp;
            while((mult--) >= 1)row += tmp;
        }
        int tam = row.length();
        build(1, 0, tam -1); 
        int q; cin >> q;
        int aux = 0;
        while(q--) {
            char op;
            cin >> op >> a >> b;
            if(op == 'F') update(1, 0, tam-1, -1);
            else if(op == 'E') update(1, 0, tam-1, -2);
            else if(op == 'I') update(1, 0, tam-1, -3); 
            else if(op == 'S') cout << "Q" << ++aux << ": " << query(1, 0, tam-1) << endl; 
            
        }
    }
    return 0;
}

