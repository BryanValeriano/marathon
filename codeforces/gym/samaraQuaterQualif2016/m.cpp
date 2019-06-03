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

const int T = 1e3 + 5;
int in[T];
vector<int> g[T];
bool eq[T][T];
bool vis[T][T];

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << flush;
    int n; cin >> n;
    char ans;
    int p = 0;

    for(int i = 1; i <= n; i++) {
        if(eq[i][(i%n)+1] or vis[i][(i%n)+1]) continue;
        cout << flush << "? " << i << " " << (i%n) + 1 << endl;
        cin >> ans; 
        if(ans == '<') in[i]++, g[(i%n)+1].pb(i);
        else if(ans == '>') in[(i%n)+1]++, g[i].pb((i%n)+1);
        else eq[i][(i%n)+1] = eq[(i%n)+1][i] = 1;
        p++;
        vis[i][(i%n)+1] = vis[(i%n)+1][i] = 1;
    }

    vector<int> ops;
    for(int i = 1; i <= n; i++) if(in[i] == 0) ops.pb(i);
    int last = 1;
    int at = ops.size();
    
    while(last != at) {
        for(int i = 1; i < ops.size(); i++) {
            int x = ops[i-1];
            int y = ops[i%ops.size()];
            if(eq[x][y] or vis[x][y]) continue;
            if(p == n+24) { cout << "! " << *ops.begin() << endl; return 0; }

            cout << flush << "? " << x << " " << y << endl;
            cin >> ans; 
            if(ans == '<') in[x]++, g[y].pb(x);
            else if(ans == '>') in[y]++, g[x].pb(y);
            else eq[x][y] = eq[y][x] = 1;
            vis[x][y] = vis[y][x] = 1;
            p++;
        }
        ops.clear();
        for(int i = 1; i <= n; i++) if(in[i] == 0) ops.pb(i);
        last = at;
        at = ops.size();
    }

    int source = *ops.begin();
    ops.clear(); 
    for(int i = 0; i < g[source].size(); i++) if(in[g[source][i]] == 1) ops.pb(g[source][i]);

    last = 1;
    at = ops.size();
    
    while(last != at) {
        for(int i = 1; i < ops.size(); i++) {
            int x = ops[i-1];
            int y = ops[i%ops.size()];
            if(eq[x][y] or vis[x][y]) continue;
            if(p == n+24) { cout << "! " << *ops.begin() << endl; return 0; }

            cout << flush << "? " << x << " " << y << endl;
            cin >> ans; 
            if(ans == '<') in[x]++, g[y].pb(x);
            else if(ans == '>') in[y]++, g[x].pb(y);
            else eq[x][y] = eq[y][x] = 1;
            vis[x][y] = vis[y][x] = 1;
            p++;
        }
        g[source] = ops;
        ops.clear();
        for(int i = 0; i < g[source].size(); i++) if(in[g[source][i]] == 1) ops.pb(g[source][i]);
        last = at;
        at = ops.size();
    }

    cout << flush << "! " << *ops.begin() << endl;

    return 0;
}

