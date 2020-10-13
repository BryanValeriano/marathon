#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 503;
const int N = 1e4+3;
int paiL[N][T];
int paiR[N][T];
int pesoL[N][T];
int pesoR[N][T];

int paiTmp[T];
int pesoTmp[T];
bool tmp[T];

vii edgs;
int n;

void init() {
    for(int i = 0; i < N; i++)
        for(int j = 1; j <= n; j++) {
            paiL[i][j] = paiR[i][j] = j;
            pesoL[i][j] = pesoR[i][j] = 1;
        }
}

int find(int *pai, int x) {
    return (x == pai[x]? x : pai[x] = find(pai,pai[x]));
}

void join(int *pai, int *peso, int a, int b) {
    a = find(pai,a);
    b = find(pai,b);
    if(a==b) return;
    if(peso[a] < peso[b]) swap(a,b);
    pai[b] = a;
    peso[a] += peso[b];
}

void update(int *paiOld, int *paiNew, int *pesoNew, int a, int b) {
    for(int i = 1; i <= n; i++) paiNew[i] = paiOld[i];
    join(paiNew,pesoNew,a,b);
}

int merge(int l, int r) {
    for(int i = 1; i <= n; i++) {
        paiTmp[i] = paiL[l][i];
        pesoTmp[i] = pesoL[l][i];
    }

    for(int i = 1; i <= n; i++) {
        join(paiTmp,pesoTmp,i,paiR[r][i]);
        tmp[i] = 0;
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        int x = find(paiTmp,i);
        if(!tmp[x]) ans++;
        tmp[x] = 1;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int m; cin >> n >> m;
    init();

    for(int i = 1; i <= m; i++) {
        int a,b; cin >> a >> b;
        edgs.eb(a,b);
        update(paiL[i-1],paiL[i],pesoL[i],a,b);
    }

    for(int i = m-1; i >= 0; i--) {
        update(paiR[i+2],paiR[i+1],pesoR[i+1],edgs[i].fi,edgs[i].se);
    }

    int q; cin >> q;

    while(q--) {
        int l,r; cin >> l >> r;
        cout << merge(l-1,r+1) << endl;
    }

    return 0;
}

