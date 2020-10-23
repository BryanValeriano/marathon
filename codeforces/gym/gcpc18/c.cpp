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
vii g[T];
int in[T];
int ans[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    while(m--) {
        int a,b,c; cin >> a >> b >> c;
        g[a].eb(b,c);
        in[b]++;
    }

    queue<int> fila;
    for(int i = 1; i <= n; i++)
        if(!in[i])
            fila.push(i);

    int r = 0;
    while(!fila.empty()) {
        int at = fila.front();
        fila.pop();
        r = max(r,ans[at]);

        for(ii e : g[at]) {
            int v,c;
            tie(v,c) = e;
            in[v]--;
            ans[v] = max(ans[v], ans[at]+c);
            if(!in[v]) fila.push(v);
        }
    }

    cout << r << endl;
    return 0;
}
