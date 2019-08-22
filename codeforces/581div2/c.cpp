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

const int T = 102;
const int M = 1e6 + 2;
int dist[T][T];
char g[T][T];
int v[M];
int n,m;
vector<int> ans;

void bfs(int at) {
    int ori = at;
    queue<int> fila;
    fila.push(at);
    dist[ori][ori] = 0;
    
    while(!fila.empty()) {
        at = fila.front(); 
        fila.pop();

        for(int i = 1; i <= n; i++) {
            if(i == ori) continue;
            if(g[at][i] == '1' and !dist[ori][i]) {
                dist[ori][i] = dist[ori][at]+1;
                fila.push(i);
            }
        }
    }
}

int bin(int pos) {
    int l = pos+1;
    int r = m;
    int at = v[pos];
    int k = l;

    while(l <= r) {
        int mid = (l+r) >> 1;
        int nxt = v[mid];
        if(dist[at][nxt] == (mid-pos)) k = mid, l = mid+1;
        else r = mid-1;
    }

    return k;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++)
            cin >> g[i][j];

    cin >> m;
    for(int i = 1; i <= m; i++) cin >> v[i];
    
    for(int i = 1; i <= n; i++) bfs(i);

    int at = 1;

    while(at != m) {
        ans.pb(v[at]);
        int nxt = bin(at);
        at = nxt;
    }

    ans.pb(v[m]);

    cout << ans.size() << endl;
    for(auto ok : ans) cout << ok << " ";
    cout << endl;

    return 0;
}

