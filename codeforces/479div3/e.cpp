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
const int T = 2e5+3;
int n,m;
int pai[T];
int in[T];
bool vis[T];
vii edgs[T];

void init() {
    for(int i = 0; i <= n; i++) {
        pai[i] = i;
    }
}

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int a, int b) {
    int x = find(a);
    int y = find(b);
    if(x == y) edgs[x].eb(a,b);
    else {
        if(edgs[x].size() < edgs[y].size()) swap(x,y);
        pai[y] = x;
        for(auto z : edgs[y]) edgs[x].pb(z);
        edgs[x].eb(a,b);
    }
}

bool isCycle(int x) {
    vis[x] = 1;
    for(auto z : edgs[x]) in[z.fi]++, in[z.se]++;
    bool ans = !edgs[x].empty();
    for(auto z : edgs[x])
        ans &= (in[z.fi] == in[z.se] and in[z.fi] == 2);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    init();

    while(m--) {
        int x,y;
        cin >> x >> y;
        join(x,y);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[find(i)]) continue;
        else ans += isCycle(find(i));
    }

    cout << ans << endl;

    return 0;
}

