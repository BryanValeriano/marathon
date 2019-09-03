#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
const int INF = 0x3f3f3f3f;

struct query { int ind, l, r; };
const int T = 3e4 + 100;
const int TT = 2e5 + 10;
const int TTT = 1e6 + 10;
const int N = sqrt(T);
int v[T];
int ans[TT];
int n, q;
vector<query> qrs;
int acum[TTT];
int resp;

void add(int ind) {
    acum[v[ind]]++;
    if(acum[v[ind]] == 1) resp++;
}

void tira(int ind) {
    acum[v[ind]]--;
    if(acum[v[ind]] == 0) resp--;
}

void mo() {
    int l = 1; 
    int r = 1;
    add(1);
    for(auto x : qrs) {
        while(r < x.r) add(++r);
        while(r > x.r) tira(r--);
        while(l < x.l) tira(l++);
        while(l > x.l) add(--l);
        ans[x.ind] = resp;
    }
}

bool cmp(const query &a, const query &b) {
    if(a.l / N != b.l / N) return a.l/N < b.l/N;
    return a.r > b.r;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) cin >> v[i];
    scanf("%d", &q);
    int l,r;
    for(int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        qrs.pb({i,l,r});
    }
    sort(qrs.begin(), qrs.end(), cmp);
    mo();
    for(int i = 0; i < q; i++) printf("%d\n", ans[i]);
    return 0;
}

