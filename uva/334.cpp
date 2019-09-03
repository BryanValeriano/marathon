#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

unordered_map<string, unordered_set<string> > g;
vector<string> v;
int n;
ll tot;
ll ans;
pair<string,string> a,b;

void init() {
    g.clear();
    v.clear();
    tot = 0;
    ans = 0;
    a = b = mk("","");
}

void read() {
    int m,k;
    string s,l;
    for(int i = 0; i < n; i++) {
        cin >> m;
        for(int j = 0; j < m; j++) {
            cin >> s;
            if(j != 0) g[l].insert(s);
            g[s].insert(s);
            v.pb(s);
            l = s;
            tot++;
        }
    }
    cin >> k;
    for(int i = 0; i < k; i++) {
        cin >> l >> s;
        g[l].insert(s);
    }
}


ll solve() {
    ans = (tot*(tot+1))/2;

    for(auto k : v)
        for(auto i : v)
            for(auto j : v)
                if(g[i].count(k) and g[k].count(j))
                    g[i].insert(j);

    for(auto x : v) ans -= g[x].size();
    
    for(auto i : v)
        for(auto j : v)
            if(!g[i].count(j) and !g[j].count(i)) {
                if(a.fi == "") a = mk(i,j);
                else { b = mk(i,j);/* return ans; */}
            }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int cont = 0;
    while(n) {
        init();
        read();
        ll ans = solve();
        if(ans > 0) cout << "Case " << ++cont << ", " << ans << " concurrent events:" << endl;
        else cout << "Case " << ++cont << ", no concurrent events." << endl;
        if(ans > 0) cout << "(" << a.fi << "," << a.se << ") ";
        if(ans > 1) cout << "(" << b.fi << "," << b.se << ") ";
        if(ans > 0) cout << endl;
        cin >> n;
    }
    return 0;
}

