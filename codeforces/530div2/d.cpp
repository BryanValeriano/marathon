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

const int T = 1e5 + 5;
vector<int> g[T];
ll s[T];
int n;

ll dfs(int at, ll maxi, int dpth) {
    ll c = 0;
    if(s[at] > maxi) c += s[at] - maxi, maxi = s[at];
    if((dpth&1) and s[at] < maxi) { cout << -1 << endl; exit(0); }

    if(!(dpth&1)) {
        c = (g[at].size()? INF : 0);
        for(auto v : g[at]) c = min(c, max(0ll,s[v] - maxi));
        maxi += c;
    }

    for(auto v : g[at]) c += dfs(v,maxi,dpth+1);

    return c;
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int x;

    for(int i = 2; i <= n; i++) {
        cin >> x;
        g[x].pb(i);
    }

    for(int i = 1; i <= n; i++) cin >> s[i];

    cout << dfs(1,0,1) << endl;

    return 0;
}

