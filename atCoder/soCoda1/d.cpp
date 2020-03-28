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
const int T = 1e5 + 5;

int pai[T];
int peso[T];
bool ok[T];

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

    if(x == y) return;
    if(peso[x] < peso[y]) swap(x,y);

    pai[y] = x;
    peso[x] += peso[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    int ans = 0;
    init(n);

    while(m--) {
        int a,b,z; cin >> a >> b >> z;
        join(a,b);
    }

    for(int i = 1; i <= n; i++) if(!ok[find(i)]) ans++, ok[find(i)] = 1;
    cout << ans << endl;

    return 0;
}

