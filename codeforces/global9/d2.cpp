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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e3+3;
int vis[T];
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        memset(vis,0,sizeof vis);
        int n; cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> v[i];
            vis[v[i]]++;
        }

        vector<int> ans;
        int corn = n;
        int w = 0;

        for(int i = 0; i < 2*n and corn; i++) {
            while(w < n and vis[w]) w++;
            bool ok = w==corn;
            int tmp = v[w-ok];
            ans.pb(w-ok+1);
            v[w-ok] = w;
            vis[w]++;
            vis[tmp]--;
            if(!vis[tmp] and tmp < w) w = tmp;
            if(ok) corn--;
        }

        cout << ans.size() << endl;
        for(int x : ans) cout << x << " ";
        cout << endl;
    }
    return 0;
}

