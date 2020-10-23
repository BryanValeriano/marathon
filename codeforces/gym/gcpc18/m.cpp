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
const int N = 502;
const int T = 1e6+5;
int mat[N][N], l[T], r[T], pai[T], sz[T], ans[T];
int gol[T][2], ori[T][2];
int mov[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
vii h[T];
vector<int> que[T];
vector<int> v;
int n,m,q;

int id(int x, int y) { return x*m + y; }

void init() {
    for(int i = 0; i < n*m+2; i++) {
        pai[i] = i;
        sz[i] = 1;
    }
}

int find(int x) {
    return (pai[x] == x? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(sz[x] < sz[y]) swap(x,y);
    pai[y] = x;
    sz[x] += sz[y];
}

bool isIn(int x, int y) {
    return (x >= 0 and x < n and y >= 0 and y < m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
            h[mat[i][j]].eb(i,j);
            v.pb(mat[i][j]);
        }

    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
    int s = v.size();

    for(int i = 0; i < q; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> ori[i][j];
            ori[i][j]--;
        }
        for(int j = 0; j < 2; j++) {
            cin >> gol[i][j];
            gol[i][j]--;
        }
        l[i] = 0;
        r[i] = s-1;
        ans[i] = v[(l[i]+r[i])>>1];
        que[(l[i]+r[i])>>1].pb(i);
    }

    for(int p = 0; p < 25; p++) {
        init();

        for(int w = 0; w < s; w++) {
            int i = v[w];

            for(ii x : h[i]) {
                for(int k = 0; k < 4; k++) {
                    int ii = x.fi + mov[k][0];
                    int jj = x.se + mov[k][1];
                    if(isIn(ii,jj) and mat[ii][jj] <= mat[x.fi][x.se]) {
                        join(id(ii,jj),id(x.fi,x.se));
                    }
                }
            }

            vii tmp;
            while(!que[w].empty()) {
                int x = que[w].back();
                que[w].pop_back();

                if(find(id(ori[x][0],ori[x][1])) == find(id(gol[x][0],gol[x][1])) and
                    i >= mat[ori[x][0]][ori[x][1]] and i >= mat[gol[x][0]][gol[x][1]]) {

                    r[x] = w-1;
                    ans[x] = v[w];
                } else l[x] = w+1;

                int mid = (l[x]+r[x])>>1;
                mid = clamp(mid,0,s-1);
                if(mid != w) que[mid].pb(x);
            }
        }
    }

    for(int i = 0; i < q; i++) cout << ans[i] << endl;

    return 0;
}

