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
int n, k;

const int T = 202;

int v;
int vis[T];

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> k;

        queue<ii> fila;
        v++;
        int x;

        for(int i = 0; i < k; i++) {
            cin >> x;
            fila.emplace(x,1);
            vis[x] = v;
        }

        int ans = 1;

        while(!fila.empty()) {
            ii at = fila.front();
            fila.pop();
            ans = max(ans,at.se);

            x = at.fi;

            if(at.fi - 1 >= 1 and vis[at.fi-1] != v) {
                vis[at.fi-1] = v;
                fila.emplace(x-1,at.se+1);
            }
            if(at.fi + 1 <= n and vis[at.fi+1] != v) {
                vis[at.fi+1] = v;
                fila.emplace(x+1,at.se+1);
            }
        }
        cout << ans << endl; 
    }
    return 0;
}

