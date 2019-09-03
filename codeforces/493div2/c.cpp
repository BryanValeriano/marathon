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
const ll INF = 0x3f3f3f3f3f3f3f;

const int T = 3e5 + 10;
string s;
bool vis[T];
int n;

void dfs(int u) {
    vis[u] = true;

    if(u-1 >= 0 and s[u-1] == '0' and !vis[u-1]) dfs(u-1);
    if(u+1 < n and s[u+1] == '0' and !vis[u+1]) dfs(u+1);
}

int main() {
    ios::sync_with_stdio(false);
    ll x,y;
    cin >> n >> x >> y;
    cin >> s;
   
    ll comps = 0;
    for(int i = 0; i < s.size(); i++) 
        if(!vis[i] and s[i] == '0') comps++, dfs(i);
  
    ll ans = y*comps;
    for(int i = comps; i > 0; i--) {
        ll tmp = i*y + (comps-i)*x; 
        ans = min(ans,tmp);
    }

    cout << ans << endl;
    return 0;
}

