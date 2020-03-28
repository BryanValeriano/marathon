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
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5 + 2;

vii xs;
vii ys;
priority_queue<ti,vti, greater<ti>>pq;
int n;
int pai[T];
int peso[T];

void init() {
    for(int i = 0; i <= n; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
}

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
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
    cin >> n;
    init();

    for(int i = 0; i < n; i++) {
        int a,b; cin >> a >> b;
        xs.eb(a,i);
        ys.eb(b,i);
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    for(int i = 1; i < n; i++) {
        pq.emplace(xs[i].fi - xs[i-1].fi, xs[i-1].se, xs[i].se);
        pq.emplace(ys[i].fi - ys[i-1].fi, ys[i-1].se, ys[i].se);
    }

    ll ans = 0;

    while(!pq.empty()) {
        ti at = pq.top();
        pq.pop();
        ll d,a,b;
        tie(d,a,b) = at;
        if(find(a) != find(b)) {
            ans += d;
            join(a,b);
        }
    }

    cout << ans << endl;

    return 0;
}

