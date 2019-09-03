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

const int T = 1e5 + 3;
bool isK[T];
int in[T];
int out[T];

vector<int> g[T];
vector<int> ans;
int n,k,vez;

void dfs(int at) {
    in[at] = 1;

    for(int v : g[at]) {
        if(!in[v]) dfs(v);
        if(in[v] and !out[v]){ cout << -1 << endl; exit(0); }
    }

    ans.pb(at);
    out[at] = 1;
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int x;

    for(int i = 0; i < k; i++) cin >> x, isK[x] = 1;

    for(int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        for(int j = 0; j < m; j++) 
            cin >> x, g[i].pb(x);
    }

    for(int i = 1; i <= n; i++) if(isK[i] and !in[i]) dfs(i);


    cout << ans.size() << endl;    
    for(auto i : ans) cout << i << " ";
    cout << endl;

    return 0;
}

