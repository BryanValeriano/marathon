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
const int T = 1e5 + 5;
vector<ll> g[T];
map<ll,int> freq;
vector<ll> v;
int h[T];
int pai[T];
int vis[T];
int vez;

int bfs(int x) {
    queue<ii> fila;
    fila.emplace(x,0);
    vez++;
    h[x] = 0;
    vis[x] = vez;
    pai[x] = x;
    int ans = INF;

    while(!fila.empty()) {
        ii at = fila.front();
        fila.pop();

        for(int nxt : g[at.fi]) {
            if(vis[nxt] == vez) {
                if(nxt != pai[at.fi]) ans = min(ans,at.se+h[nxt]+1);
                continue;
            }
            h[nxt] = at.se+1;
            pai[nxt] = at.fi;
            vis[nxt] = vez;
            fila.emplace(nxt,h[nxt]);
        }
    }

    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int ans = INF;

    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        freq[x]++;
        if(freq[x] < 4) v.pb(x);
    }

    n = v.size();

    if(n <= 1000) {
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(v[i]&v[j]) g[i].pb(j), g[j].pb(i);
        for(int i = 0; i < n; i++) ans = min(ans,bfs(i));
    } else ans = 3;

    cout << (ans == INF? -1 : ans) << endl;

    return 0;
}

