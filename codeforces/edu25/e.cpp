#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 5;
priority_queue<int, vector<int> > pq;
vector<int> g[T];
int ans[T];
int in[T];
int n,m;


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 0; i < m; i++) { 
        int u,v;
        cin >> u >> v;
        g[v].pb(u);
        in[u]++;
    }

    for(int i = 1; i <= n; i++) if(!in[i]) pq.push(i);
    int niv = n;

    while(!pq.empty()) {
        int at = pq.top(); 
        pq.pop();
        ans[at] = niv--;


        for(auto v : g[at]) {
            in[v]--;
            if(!in[v]) pq.push(v);
        }
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

