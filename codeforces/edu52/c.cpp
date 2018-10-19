#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 2e5 + 3;
ll seg[4*T + 4];
ll lazy[4*T + 4];

void prop(int node, int i, int j) {
    seg[node] += lazy[node] * (j-i+1);
    if(i != j) {
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }
    lazy[node] = 0;
}

ll query(int node, int i, int j, int a, int b) {
    prop(node,i,j);
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node];

    int meio = (i+j) >> 1;
    return query(2*node, i, meio, a, b) + query(2*node+1, meio + 1, j, a, b);
}

void update(int node, int i, int j, int a, int b, int v) {
    prop(node, i, j);
    if(i > b or j < a) return;
    if(i >= a and j <= b) {
        lazy[node] += v;
        prop(node, i, j);
        return;
    }
    int meio = (i+j)>>1;
    update(2*node, i, meio, a, b, v);
    update(2*node+1, meio+1, j, a, b, v);
    seg[node] = seg[2*node] + seg[2*node+1];
    return;
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int mini = INF;
    int maxi = 0;
    int aux;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        mini = min(mini, aux);
        maxi = max(maxi, aux);
        update(1, 0, T, 1, aux, 1); 
    }
    int top = maxi;
    int cut = 0;
    int point = maxi;
    while(top > mini) {
        ll tot = query(1, 0, T, top, point);
        while(tot < k && top > mini) {
            top--;
            tot = query(1, 0, T, top, point);
        }
        if(tot == k) top--;
        else if(top == point) top--;
        cut++;
        point = top;
    }
    cout << cut << endl;

    return 0;
}

