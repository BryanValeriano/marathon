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

const int T = 1e6 + 10;
int v[T];
int ans[T];
bool vis[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) ans[i] = v[v[v[i]]];
    for(int i = 1; i <= n; i++) { 
        cout << v[i] << " " << ans[ans[i]] << endl;
        if(v[i] != ans[ans[i]]) { cout << -1 << endl; return 0; }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}

