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
typedef tuple<ll,int,int> ti;
typedef vector<ii> vii;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 101;
const int N = 201;

vti v;
int n,e;
int pai[T];
int peso[T];
bool used[N];

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

void init() {
    for(int i = 0; i <= n; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
}

int kruskal(int prob) {
    int ans = 0;
    init();

    for(int i = 0; i < e; i++) {
        if(i == prob) continue;
        int c,a,b;
        tie(c,a,b) = v[i];

        if(find(a) != find(b)) {
            join(a,b);
            ans += c;
            if(prob == -1) used[i] = 1;
        }
    }

    bool ok = 1;
    for(int i = 2; i <= n and ok; i++)
        ok &= (find(i) == find(i-1));

    return (ok? ans : INF);
}

int main() {
    ios_base::sync_with_stdio(false);
    int cont = 0;
    int tc; cin >> tc;
    while(tc--) {
        v.clear();
        cin >> n >> e;

        for(int i = 0; i < e; i++) {
            int a,b,c; cin >> a >> b >> c;
            used[i] = 0;
            v.eb(c,a,b);
        }

        if(e < n-1) {
            cout << "Case #" << ++cont << " : No way" << endl;
            continue;
        }

        sort(v.begin(),v.end());

        int x = kruskal(-1);
        if(x == INF) {
            cout << "Case #" << ++cont << " : No way" << endl;
            continue;
        }

        int y = INF;

        for(int i = 0; i < e; i++)
            if(used[i]) y = min(y,kruskal(i));

        if(y == INF) {
            cout << "Case #" << ++cont << " : No second way" << endl;
            continue;
        }

        cout << "Case #" << ++cont << " : " << y << endl;
    }

    return 0;
}

