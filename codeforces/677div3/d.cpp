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
const int T = 5e3+5;
int pai[T], peso[T], v[T];

void init(int n) {
    for(int i = 1; i <= n; i++) {
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
    if(peso[y] > peso[x]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        vii ans, ok;
        int n; cin >> n;
        init(n);

        for(int i = 1; i <= n; i++) cin >> v[i];

        for(int i = 1; i <= n; i++)
            for(int j = i+1; j <= n; j++)
                if(v[i] != v[j]) ok.eb(i,j);

        for(ii e : ok) {
            if(find(e.fi) != find(e.se)) {
                ans.eb(e);
                join(e.fi,e.se);
            }
        }

        if(ans.size() == n-1) {
            cout << "YES\n";
            for(ii e : ans) cout << e.fi << " " << e.se << endl;
        } else cout << "NO\n";
    }
    return 0;
}

