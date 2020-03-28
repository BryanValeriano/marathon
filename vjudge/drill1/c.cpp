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
const int T = 1e3 + 2;

string g[T];
int vis[T][T];
int vez[T][T];
int d[T][T];
deque<ii> fila;
int n,m,v;

int mov[8][2] = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };

bool isIn(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < m);
}

int bfs(int s1, int s2) {
    v++;

    while(!fila.empty()) {
        ii at = fila.front();
        fila.pop_front();

        vez[at.fi][at.se] = v;
        vis[at.fi][at.se] = 3;
        if(at.fi == s1 and at.se == s2) return d[at.fi][at.se];

        for(int k = 0; k < 8; k++) {
            bool cost = (k != (g[at.fi][at.se]-'0'));
            int i = at.fi + mov[k][0];
            int j = at.se + mov[k][1];
            if(!isIn(i,j)) continue;

            if(vez[i][j] == v) {
                if(!cost) d[i][j] = min(d[i][j], d[at.fi][at.se]);
                if((vis[i][j]&1) or cost) continue;
                vis[i][j] = 1;
                fila.emplace_front(i,j);
            } else {
                if(!cost) fila.emplace_front(i,j), vis[i][j] = 1;
                else fila.emplace_back(i,j), vis[i][j] = 2;
                vez[i][j] = v;
                d[i][j] = d[at.fi][at.se] + cost;
            }
        }
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> g[i];
    int q; cin >> q;
    while(q--) {
        int s1,s2,t1,t2;
        cin >> s1 >> s2 >> t1 >> t2;
        s1--, s2--, t1--,t2--;
        fila.clear();
        fila.emplace_front(s1,s2);
        d[s1][s2] = 0;
        cout << bfs(t1,t2) << endl;
    }
    return 0;
}

