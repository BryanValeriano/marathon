#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

unordered_map<string, vector<string> > g;
unordered_set<string> vis;
vector<string> bag;

void dfs(string u) {
    vis.insert(u);
    for(auto v : g[u]) 
        if(!vis.count(v)) dfs(v);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        g.clear();
        vis.clear();
        bag.clear();
        int n,k; cin >> n >> k;
        string x,y;
        int z;

        for(int i = 0; i < n; i++) {
            cin >> x >> z;
            bag.pb(x);
            for(int j = 0; j < z; j++) {
                cin >> y;
                g[x].pb(y);
            }
        }

        for(int i = 0; i < k; i++) {
            cin >> x;
            if(!vis.count(x)) dfs(x);
        }

        for(int i = 0; i < n; i++)
            if(vis.count(bag[i])) cout << bag[i] << endl;

    } 
    return 0;
}

