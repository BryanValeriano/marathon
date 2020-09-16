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
const int T = 2e5+5;
int full[T];
int in[T];
vector<int> g[T];

bool bfs(int at, int gol) {
    queue<int> fila;
    fila.push(at);
    full[at] = in[at] = INF;

    while(!fila.empty()) {
        at = fila.front();
        fila.pop();
        if(at==gol) return 1;
        for(int v : g[at]) {
            in[v]--;
            if(in[v] == (full[v]>>1)) fila.push(v);
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int c,p,x,l;
    cin >> c >> p >> x >> l;
    while(p--) {
        int x,y; cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
        in[x] = full[x] = in[x]+1;
        in[y] = full[y] = in[y]+1;
    }
    cout << (bfs(l,x)? "leave\n" : "stay\n");
    return 0;
}

