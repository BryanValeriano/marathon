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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 2;
bool vis[T];
vector<int> g[T];
int n,m;
int ans [T];

void bfs() {
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(1);
    int c = 0;
    vis[1] = 1;

    while(!pq.empty()) {
        int at = pq.top();
        pq.pop();
        ans[c++] = at;

        for(int v : g[at]) {
            if(!vis[v]) {
                vis[v] = 1;
                pq.push(v);
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    bfs();
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

