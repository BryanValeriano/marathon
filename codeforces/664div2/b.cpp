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
const int T = 102;
int n,m,x,y;
bool vis[T][T];
int mov[4][2] = { {1,0}, {0,-1}, {-1,0}, {0,1} };

bool inside(int i, int j) {
    return (i >= 1 and i <= n and j >= 1 and j <= m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> x >> y;
    vii ans;
    ans.eb(x,y);
    vis[x][y] = 1;

    while(ans.size() < n*m) {
        for(int k = 0; k < 4 && ans.size() < n*m; k++) {
            int xx = x+mov[k][0];
            int yy = y+mov[k][1];
            while(inside(xx,yy)) {
                if(!vis[xx][yy]) {
                    vis[xx][yy] = 1;
                    ans.eb(xx,yy);
                    x = xx;
                    y = yy;
                    xx = x+mov[k][0];
                    yy = y+mov[k][1];
                }
            }
        }
    }

    for(auto v : ans) cout << v.fi << " " << v.se << endl;
    return 0;
}

