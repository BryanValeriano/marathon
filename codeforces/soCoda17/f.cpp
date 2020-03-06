#include <bits/stdc++.h>
using namespace std;

#define wat(i,n) _back
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
const int T = 1e5 + 3;

int n,m;
bool vis[T];
set<ii> bag;
set<int> possible;

void bfs(int at) {
    vis[at] = 1;
    queue<int> fila;
    fila.push(at);
    possible.erase(at);

    while(!fila.empty()) {
        int at = fila.front();
        fila.pop();

        vector<int> apaga;

        for(auto v : possible) {
            if(vis[v] or bag.count(mk(min(at,v),max(at,v)))) continue;
            vis[v] = 1;
            fila.push(v);
            apaga.pb(v);
        }

        for(auto v : apaga) possible.erase(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) possible.insert(i);

    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        if(a > b) swap(a,b);
        bag.emplace(a,b);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) ans++, bfs(i);
    }

    cout << ans-1 << endl;
    return 0;
}

