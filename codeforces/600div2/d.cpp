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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e5 + 3;
int pai[T], peso[T], mini[T], maxi[T];
bool vis[T];
set<int> bag;
int ans = 0;

void init() {
    for(int i = 0; i < T; i++) {
        pai[i] = i;
        peso[i] = i;
        mini[i] = maxi[i] = i;
    }
}

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(peso[y] > peso[x]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
    maxi[x] = max(maxi[x],maxi[y]);
    mini[x] = min(mini[x],mini[y]);
}

void check(int u) {
    vis[find(u)] = 1;
    vector<int> del;
    for(auto i = bag.lower_bound(mini[u]); i != bag.end() and *i <= maxi[u]; ++i) {
        int x = *i;
        if(find(x) != find(u)) {
            ans++;
            join(x,u);
        }
        del.pb(x);
    }
    for(auto x : del) bag.erase(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    init();
    cin >> n >> m;
    for(int i = 1; i <= n; i++) bag.insert(i);

    for(int i = 0; i < m; i++) {
        int x,y; cin >> x >> y;
        join(x,y);
    }

    vector<ii> tmp;
    for(int i = 1; i <= n; i++) {
        if(!vis[find(i)]) {
            vis[find(i)] = 1;
            tmp.eb(mini[find(i)]-maxi[find(i)],find(i));
        }
    }

    sort(tmp.begin(), tmp.end());

    for(ii ok : tmp) {
        int u = find(ok.se);
        check(u);
    }

    cout << ans << endl;
    return 0;
}

