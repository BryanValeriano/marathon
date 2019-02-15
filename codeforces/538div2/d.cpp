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
const int T = 5e3 + 10;
int n;
int v[T];
bool vis[T];
int comps[T];

void dfs(int u) {
    vis[u] = true;
    
    if(u + 1 < n and !vis[u+1] and v[u+1] == v[u]) dfs(u+1);
    if(u - 1 >= 0 and !vis[u-1] and v[u-1] == v[u]) dfs(u-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    int ans = 0;
    int maxi = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i);
            comps[v[i]]++;
            maxi = max(maxi, comps[v[i]]);
            ans++;
        }
    }
    cout << ans - maxi << endl;
    return 0;
}

