#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,string> ss;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
const int T = 2e3 + 5;
int ori, dest;

map<int, vector<ss> > id;
map<string, int> track;
bool vis[T];
int dp[T];

int solve(int atual, char prob) {
    if(vis[atual]) return INF;
    vis[atual] = true;

    if(atual == dest) {
        vis[atual] = false;
        return 0;
    }

    int &r = dp[atual];
    if(r != -1) {
        vis[atual] = false;
        return r;
    }

    int ans = INF;
    for(auto v : id[atual]) {
        if(v.se[0] != prob) {
            int cust = v.se.size();
            ans = min(ans, solve(v.fi, v.se[0]) + cust);
        }
    }
    vis[atual] = false;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int m;
    string o, d;
    cin >> m;
    while(m) {
        int cont = 0;
        cin >> o >> d;
        string a, b, c;
        id.clear();
        track.clear();
        track[o] = ++cont;
        if(o != d) track[d] = ++cont;
        ori = track[o];
        dest = track[d];
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            if(!track.count(a)) track[a] = ++cont;
            if(!track.count(b)) track[b] = ++cont;
            id[track[a]].pb(ss(track[b],c));
            id[track[b]].pb(ss(track[a],c));
        }
        memset(dp, -1, sizeof dp);
        int ans = solve(ori, 'z' + 1);
        if(ans >= INF-10) cout << "impossivel" << endl;
        else cout << ans << endl;
        cin >> m;
    }
    return 0;
}

