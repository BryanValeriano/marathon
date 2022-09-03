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
const int T = 30;
set<ii> bag;
vector<int> g[T];
string s,t;
int n,m,k;

void reset() {
    for(int i = 0; i < T; i++) g[i].clear();
    bag.clear();
}

void build() {
    cin >> s >> t;
    for(int i = 0; i+k < s.size(); i++) {
        bag.emplace(s[i]-'a',s[i+k]-'a');
    }

    for(int i = 0; i < t.size(); i++)
        g[t[i]-'a'].pb(i);
}

ll solve(int x, int y) {
    int l = 0;
    int r = 0;
    ll ans = 0;
    while(l < g[x].size()) {
        while(r < g[y].size() && g[y][r] < g[x][l]) r++;
        if(r == g[y].size()) break;
        ans += (g[y].size()-r);
        l++;
    }
    return ans;
}

ll corn() {
    ll ans = 0;
    for(int i = 0; i < t.size(); i++)
        ans += (bag.count(mk(t[i]-'a',t[i]-'a')));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m >> k;
        k--;
        reset();
        build();
        ll ans = 0;
        for(ii x : bag) ans += solve(x.fi, x.se);
        cout << ans << endl;
    }
    return 0;
}

