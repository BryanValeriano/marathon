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
const int T = 55;
const int N = 1030;
int v[T][T];
int mov[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int dp[T][T][N];
int n, m, startx, starty, endx, endy;

struct node { 
    int x, y, mask; 
    
    bool operator < (const node &b) const {
        int x = __builtin_popcount(mask);
        int y = __builtin_popcount(b.mask);
        if(x != y) return x < y;
        return false;
    }
    bool operator > (const node &b) const {
        int x = __builtin_popcount(mask);
        int y = __builtin_popcount(b.mask);
        if(x != y) return x > y;
        return false;
    }
};

bool isIn(int x, int y) {
    return (x >= 0 and x < n and y >= 0 and y < n);
}

bool isGol(int x, int y) {
    return (x == endx and y == endy);
}

int bfs() {
    priority_queue< node, vector<node>, greater<node> >pq;
    pq.push({ startx, starty, 0 | (1<<(v[startx][starty])) });
    while(!pq.empty()) {
        node atual = pq.top();
        pq.pop();
        if(isGol(atual.x, atual.y)) return atual.mask;
        for(int k = 0; k < 4; k++) {
            int xx = atual.x + mov[k][0];
            int yy = atual.y + mov[k][1];
            if(isIn(xx,yy)) {
                node tmp = atual;
                tmp.x = xx; tmp.y = yy;
                tmp.mask |= (1<<v[xx][yy]);
                int &r = dp[xx][yy][tmp.mask];
                int z = __builtin_popcount(tmp.mask);
                if(z < r) { r = z; pq.push(tmp); }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc; cin >> tc; 
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> v[i][j];
        cin >> startx >> starty >> endx >> endy;
        memset(dp, INF, sizeof dp);
        int ans = bfs();
        cout << __builtin_popcount(ans) << endl;
    }
    return 0;
}

