#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,int> ti;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e3 + 3;

int n;
int mat[2][T][T];
int dist[2][T][T];
bool vis[2][T][T];
ii pai[2][T][T];
int mov[2][2] = { {1,0}, {0,1} };

bool isIn(int i, int j) {
    return (i >= 0 and i < n and j >= 0 and j < n);
}

int z;

int dij() {
    memset(dist, INF, sizeof dist);
    priority_queue<ti, vector<ti>> pq;

    dist[0][0][0] = mat[0][0][0];
    dist[1][0][0] = mat[1][0][0];

    pq.emplace(-mat[0][0][0],0,0);
    int ans = INF;

    while(!pq.empty()) {
        ti at = pq.top();
        pq.pop();
        int i,j,d;
        tie(d,i,j) = at;
        d = -d;

        if(i == n-1 and j == n-1) {
            if(d < ans) {
                ans = d;
                z = 0;
            }
            continue;
        }

        if(vis[0][i][j]) continue;
        vis[0][i][j] = 1;

        for(int k = 0; k < 2; k++) {
            int ii = i + mov[k][0];
            int jj = j + mov[k][1];
            if(isIn(ii,jj)) {
                int nd = d + mat[0][ii][jj];
                ti x = make_tuple(-nd,ii,jj);
                if(dist[0][ii][jj] > nd) {
                    pq.emplace(x);
                    dist[0][ii][jj] = nd;
                    pai[0][ii][jj] = mk(i,j);
                }
            }
        }
    }

    pq.emplace(-mat[1][0][0],0,0);

    while(!pq.empty()) {
        ti at = pq.top();
        pq.pop();
        int i,j,d;
        tie(d,i,j) = at;
        d = -d;

        if(i == n-1 and j == n-1) {
            if(d < ans) {
                ans = d;
                z = 1;
            }
            continue;
        }

        if(vis[1][i][j]) continue;
        vis[1][i][j] = 1;

        for(int k = 0; k < 2; k++) {
            int ii = i + mov[k][0];
            int jj = j + mov[k][1];
            if(isIn(ii,jj)) {
                int nd = d + mat[1][ii][jj];
                ti x = make_tuple(-nd,ii,jj);
                if(dist[1][ii][jj] > nd) {
                    pq.emplace(x);
                    dist[1][ii][jj] = nd;
                    pai[1][ii][jj] = mk(i,j);
                }
            }
        }
    }

    return ans;
}

void build(int ori, int i, int j) {
    if(i == 0 and j == 0) return;
    build(ori,pai[ori][i][j].fi,pai[ori][i][j].se);
    if(pai[ori][i][j].fi != i) cout << 'D';
    else cout << 'R';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x; cin >> x;
            while(x % 2 == 0) mat[0][i][j]++, x /= 2;
            while(x % 5 == 0) mat[1][i][j]++, x /= 5;
        }
    }

    cout << dij() << endl;
    build(z,n-1,n-1);
    cout << endl;

    return 0;
}

