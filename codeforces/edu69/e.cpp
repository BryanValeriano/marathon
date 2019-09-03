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

const int T = 2e5 + 5;
const int MOD = 1e9 + 7;

vii out;
vector<int> ins;
int dol[T][2];
int seek = INF;
int n;
vector<int> g[T];
bool vis[T];
ll tam[T];
int in[T];

bool notGreat(int i) {
    auto x = upper_bound(ins.begin(), ins.end(), dol[i][0]);
    return (x == ins.end());
}

void dfs(int at) {
    if(vis[at]) return;
    if(g[at].size() == 0) { tam[at] = 1; return; }
    vis[at] = 1;
    int ans = 0;
    
    for(int nxt : g[at]) { 
        int ok = vis[nxt];
        if(g[nxt].size() == 0) ans = (ans + 1) % MOD;
        else { dfs(nxt), ans = (ans + tam[nxt])%MOD; }
    }
   
    tam[at] = ans;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> dol[i][0] >> dol[i][1];
        out.eb(dol[i][0],i);
        ins.pb(dol[i][1]);
    }

    sort(out.begin(), out.end());

    for(int i = 0; i < n; i++) {
        ii x = mk(dol[i][1],0);
        auto ok = lower_bound(out.begin(), out.end(), x);
        while(ok != out.begin() and ok->fi > dol[i][1]) ok--;
        if(ok->fi <= dol[i][1]) seek = min(seek, dol[i][1] - ok->fi);
    }

    for(int i = 0; i < n; i++) {
        ii x = mk(dol[i][1] - seek,0);
        auto ok = lower_bound(out.begin(), out.end(), x);
        while(ok != out.end() and dol[i][1] - seek == ok->fi) g[i].pb(ok->se), in[ok->se]++, ok++;
        //cout << i+1 << " : ";
        //for(auto nxt : g[i]) cout << nxt+1 << " ";
        //cout << endl;
    }


    ll ans = 0;

    for(int i = 0; i < n; i++) 
        if(!vis[i] and !in[i] and notGreat(i)) {
            dfs(i);
            cout << i+1 << " " << tam[i] << endl;
            ans = (ans + tam[i]) % MOD;
        }

    cout << ans << endl;

    return 0;
}

