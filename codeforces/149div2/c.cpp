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
const int INF = 1e9 + 10;

unordered_map<int, vii> bag;
unordered_map<int, unordered_set<int> > track;
unordered_map<int, unordered_set<int> > vis;
int a0,b0,af,bf;

int mov[8][2] = { {0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1} };

struct node {
    int x,y,lvl;
};

int bfs() {
    queue<node> lista;
    lista.push({a0,b0,0});
    vis[a0].insert(b0);

    while(!lista.empty()) {
        node at = lista.front();
        lista.pop();

        if(at.x == af and at.y == bf) return at.lvl;

        for(int k = 0; k < 8; k++) {
            int xx = at.x + mov[k][0];
            int yy = at.y + mov[k][1];
            if(track[xx].count(yy) and !vis[xx].count(yy)) {
                vis[xx].insert(yy);
                lista.push({xx,yy, at.lvl+1});
            }
        }
    }

    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin >> a0 >> b0 >> af >> bf;
    int n; cin >> n;
    int r,a,b;
    while(n--) {
        cin >> r >> a >> b;
        bag[r].eb(a,b);
    }

    for(auto x : bag) {
        sort(x.se.begin(), x.se.end());
        int iter = 0;
        for(auto y : x.se) {
            iter = max(iter, y.fi);
            while(iter <= y.se) track[x.fi].insert(iter), iter++;
            
        }
    }

    int ans = bfs();
    cout << ans << endl;

    return 0;
}

