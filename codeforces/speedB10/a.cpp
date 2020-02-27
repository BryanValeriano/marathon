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

vector<int> g[T];
vector<int> ans;
int ini[T], gol[T];
int n;

void solve(int at, int pai, int niv, int tmp[]) {
    int ok[2] = {tmp[0],tmp[1]};

    if(ok[niv]) ini[at] = !ini[at];

    if(ini[at] != gol[at]) {
        ans.pb(at);
        ok[niv] = !ok[niv];
        ini[at] = !ini[at];
    }

    for(int v : g[at]) {
        if(v == pai) continue;
        solve(v,at,!niv,ok);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    for(int i = 1; i <= n; i++) cin >> ini[i];
    for(int i = 1; i <= n; i++) cin >> gol[i];
    int ok[2] = {0,0};

    solve(1,0,1,ok);

    cout << ans.size() << endl;
    for(auto x : ans) cout << x << endl;

    return 0;
}

