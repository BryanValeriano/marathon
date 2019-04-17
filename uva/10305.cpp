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

const int T = 105;
vector<int> g[T];
int in[T];

void init() {
    for(int i = 1; i <= 100; i++) {
        g[i].clear();
        in[i] = 0;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    while(n or m) {
        int x,y;
        init();
        for(int i = 0; i < m; i++) {
            cin >> x >> y;
            g[x].pb(y);
            in[y]++;
        }

        queue<int> bag;

        for(int i = 1; i <= n; i++)
            if(!in[i]) bag.push(i);

        while(!bag.empty()) {
            int u = bag.front();
            bag.pop();
            cout << u << " ";
            for(auto v : g[u]) {
                in[v]--;
                if(!in[v]) bag.push(v);
            }
        }

        cout << endl;
        cin >> n >> m;
    }    
    return 0;
}

