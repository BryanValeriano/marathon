#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int T = 1e5 + 5;
int v[T];
int seg[4*T + 1];
int n;

void build(int node, int i, int j) {
    if(i == j) seg[node] = v[i];
    else {
        int meio = (j + i) >> 1;
        build(2*node, i, meio);
        build(2*node+1, meio+1, j);
        seg[node] += seg[2*node] + seg[2*node+1];
    }
}

int query(int node, int i, int j, int a, int b) {
    if(j < a or i > b) return 0;
    if(i >= a and j <= b) return seg[node];
    int meio = (i + j) >> 1;
    return query(2*node, i, meio, a, b) + query(2*node+1, meio+1, j, a, b);
}

void update(int node, int i, int j, int p, int val) {
    if(j < p or i > p) return;
    if(i >= p and j <= p) seg[node] + val; 
	else {
		int meio = (i + j) >> 1;
		update(2*node, i, meio, p, val);
		update(2*node+1, meio+1, j, p, val);
		seg[node] = seg[2*node] + seg[2*node + 1];
		}
} 
 
int main()
{
    int q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) 
        cin >> v[i];
    build(1, 0, n-1);
    int a, b, op;
    
    return 0;
}

