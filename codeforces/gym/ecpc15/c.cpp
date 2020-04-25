#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5 + 4;
int pai[T], peso[T], his[T];
vti querys[T];
vti input;
int l[T], r[T], ans[T];

void init(int n, int m) {
    for(int i = 1; i <= m; i++) {
        l[i] = 1, r[i] = m;
        querys[i].clear();
        ans[i] = -1;
    }
    input.clear();
}

void uf(int n) {
    for(int i = 0; i <= n; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
}

int find(int x) {
    return (pai[x] == x? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
}


int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n,m; cin >> n >> m;
        init(n,m);
        uf(n);

        for(int i = 1; i <= m; i++) {
            int q,a,b; cin >> q >> a >> b;
            input.eb(q,a,b);
            if(q==2)querys[(l[i]+r[i])>>1].eb(i,a,b);
            else ans[i] = -2;
        }

        for(int k = 0; k <= log2(m)+4; k++) {
            uf(n);
            for(int i = 1; i <= m; i++) {
                int q,a,b;
                tie(q,a,b) = input[i-1];
                if(q == 1) join(a,b);
                while(querys[i].size()) {
                    auto chute = querys[i].back();
                    querys[i].pop_back();
                    int t,u,v;
                    tie(t,u,v) = chute;
                    if(find(u) == find(v)) ans[t] = i, r[t] = i-1;
                    else l[t] = i+1;
                    int mid = (l[t]+r[t])>>1;
                    if(l[t] <= r[t] and i != mid) querys[mid].eb(t,u,v);
                }
            }
        }

        for(int i = 1; i <= m; i++)
            if(ans[i] >= -1) cout << (ans[i]<=i?ans[i]:-1) << endl;
    }
    return 0;
}

