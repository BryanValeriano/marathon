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
const int T = 2e5 + 5;

int n,m,k;
int r[T];
int low[T];
int high[T];

int in2[T][2];
bool vis[T][2];
int in[T];

vector<int> g[T][2];
set<int> bag;

void dfs(int at, int op) {
    vis[at][op] = 1;

    for(int v : g[at][op]) {
        in2[v][op]--;
        if(r[at]) {
            if(!op) high[v] = min(high[v],high[at]-1);
            else low[v] = max(low[v],low[at]+1);
        }
        if(!in2[v][op] and !vis[v][op]) dfs(v,op);
    }
}

bool bfs() {
    //quero dar o rank mais alto para quem tem o maior low?
    //fi = low, se = node

    priority_queue<ii,vii, greater<ii>> pq;
    for(int i = 1; i <= n; i++)
        if(!in[i]) pq.emplace(low[i],i);

    while(!pq.empty()) {
        ii at = pq.top();
        pq.pop();

        //cout << at.se << " " << low[at.se] << " " << high[at.se] << endl;

        if(low[at.se] > high[at.se]) return 0;

        if(!r[at.se]) {

            if(bag.size()) {
                auto ok = bag.lower_bound(high[at.se]);
                if((ok == bag.end() or *ok > high[at.se]) and ok != bag.begin()) ok--;
                r[at.se] = min(*ok,high[at.se]);
            } else r[at.se] = min(k,high[at.se]);

            r[at.se] = max(low[at.se],r[at.se]);

            bag.erase(r[at.se]);
        }

        //cout << at.se << " = " << r[at.se] << endl;

        for(int v : g[at.se][0]) {
            in[v]--;
            if(r[v] and r[v] > r[at.se]) return 0;
            high[v] = min(high[v],r[at.se]-1);
            if(!in[v]) pq.emplace(low[v],v);
        }
    }

    return (bag.empty());
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(high, INF, sizeof high);

    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) bag.insert(i);

    for(int i = 1; i <= n; i++) {
        cin >> r[i];
        if(r[i]) {
            low[i] = high[i] = r[i];
            bag.erase(r[i]);
        }
    }

    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        in[b]++,
        in2[b][0]++, in2[a][1]++;
        g[a][0].pb(b);
        g[b][1].pb(a);
    }

    for(int i = 1; i <= n; i++) {
        if(!in2[i][0] and !vis[i][0]) dfs(i,0);
        if(!in2[i][1] and !vis[i][1]) dfs(i,1);
    }

    for(int i = 1; i <= n; i++) {
        if(in2[i][0] or in2[i][1]) {
            cout << -1 << endl;
            return 0;
        }
    }

    bool ans = 1;
    if(!bfs()) cout << -1;
    else for(int i = 1; i <= n; i++) ans &= (r[i] <= k and r[i] >= 1);

    if(ans) for(int i = 1; i <= n; i++) cout << r[i] << " ";
    else cout << -1;
    cout << endl;

    return 0;
}

