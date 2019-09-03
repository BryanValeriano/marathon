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
const int T = 2e5 + 10;
int n;
int id[T];
int seg[4*T + 4];
int lazy[4*T + 4];

void prop(int node, int i, int j) {
    if(lazy[node] == -1) seg[node] = 0;
    else seg[node] += lazy[node] * (j-i+1);
    if(i != j) {
        if(lazy[node] == -1) {
            lazy[2*node] = -1; 
            lazy[2*node+1] = -1;
        } else {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
    }
    lazy[node] = 0;
}

void update(int node, int i, int j, int a, int b, int val) {
    prop(node, i, j);
    if(i > b or j < a) return;
    if(i >= a and j <= b) {
        if(val == -1) lazy[node] = -1;
        else lazy[node] += val;
        prop(node, i, j);
    } else {
        int meio = (i + j) / 2;
        update(2*node, i, meio, a, b, val);
        update(2*node+1, meio + 1, j, a, b, val);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

int query(int node, int i, int j, int a, int b) {
    prop(node, i, j);
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];
    int meio = (i + j) / 2;
    return query(2*node, i, meio, a, b) + query(2*node + 1, meio + 1, j, a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int aux;
    for(int i = 1; i <= n; i++) {
        cin >> aux;
        id[aux] = i;
    }
    int q = n;
    update(1, 1, n, 1, n, 1);
    while(q--) {
        cin >> aux;
        cout << query(1, 1, n, 1, id[aux]) << " ";
        update(1, 1, n, 1, id[aux], -1);
    }
    cout << endl;
    return 0;
}

