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
const int T = 1e5+2;
int v[T], peso[T], pai[T];
vector<int> g[T];

void init(int n) {
    for(int i = 0; i < n; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
}

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return 0;
    if(peso[x] < peso[y]) swap(x,y);
    peso[x] += peso[y];
    pai[y] = x;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("dream.in","r",stdin);
    int t; cin >> t;
    int cont = 0;
    while(t--) {
        int n; cin >> n;
        init(n);
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            cin >> v[i];
            g[v[i]].pb(i);
            maxi = max(v[i],maxi);
        }
        ll ans = 0;
        for(int k = maxi; k >= 1; k--) {
            int last = -1;
            for(int j = k; j < T; j += k) {
                for(int p : g[j]) {
                    if(last == -1) last = p;
                    else if(join(last,p)) ans += (ll)k;
                }
            }
        }
        for(int i = 0; i < n; i++) g[v[i]].clear();
        cout << "Case " << ++cont << ": " << ans << endl;
    }
    return 0;
}

