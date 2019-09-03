#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 5e3 + 2;

int seg[4*T][3];
int v[T];
struct p { int a,b,c; };
vector<p> paint;
int qtd1[T];
int a,b;

void build(int node, int i, int j, int val) {
    if(i == j) seg[node][val] = (v[i] == val);
    else {
        int mid = (i+j) >> 1;
        build(2*node, i, mid, val);
        build(2*node+1, mid+1, j, val);
        seg[node][val] = seg[2*node][val] + seg[2*node+1][val];
    }
}

int query(int node, int i, int j, int val) {
    if(i > b or j < a) return 0;
    if(i >= a and j <= b) return seg[node][val];
    int mid = (i+j) >> 1;
    return query(2*node, i, mid, val) + query(2*node+1, mid+1, j, val);
}

bool cmp(const p &a, const p &b) {
    return a.c < b.c;
}

int main() {
    int n,q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        paint.pb({a,b,0});
        for(int i = a; i <= b; i++) v[i]++;
    }
    
    
    build(1,1,n,0);
    build(1,1,n,1);
    build(1,1,n,2);

    a = 1, b = n;
    int tot = n - query(1,1,n,0);
    int ans = 0;

    for(int i = 0; i < q; i++) {
        a = paint[i].a, b = paint[i].b;
        paint[i].c = query(1,1,n,1);
    }

    sort(paint.begin(), paint.end(), cmp);
    ans = tot- paint[0].c - paint[1].c;
    if(paint[0].b >= paint[1].a) {
        a = paint[0].b, b = paint[1].a;
        ans -= query(1,1,n,2);
    }
    if(paint[1].b >= paint[0].a) {
        a = paint[1].b, b = paint[0].a;
        ans -= query(1,1,n,2);
    }

    printf("%d\n", ans);
    return 0;
}

