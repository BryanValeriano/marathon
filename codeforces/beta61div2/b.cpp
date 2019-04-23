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

const int T = 1e3 + 10;
int v[T];
int vis[T];
int vez;
int n;

int dfs(int u) {
    vis[u] = vez;
    int x = 1;

    if(u-1 >= 0 and v[u-1] <= v[u] and vis[u-1] != vez) x += dfs(u-1);
    if(u+1 < n and v[u+1] <= v[u] and vis[u+1] != vez) x += dfs(u+1);

    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];

    int ans = 0;
    for(int i = 0; i < n; i++) {
        vez++;
        ans = max(ans, dfs(i));
    }

    cout << ans << endl;

    return 0;
}

