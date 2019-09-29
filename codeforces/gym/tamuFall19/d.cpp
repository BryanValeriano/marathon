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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 102;
char mat[T][T][T];
int vis[T][T][T];
int ans[T][T][T];
int comp[T][T][T];

int mov[6][3] = { {1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1} };
int x,y,z,f,cont;

bool isIn(int i, int j, int p) {
    return (i >= 0 and i < z and j >= 0 and j < y and p >= 0 and p < x);
}

int dfs(int a, int b, int c) {
    vis[a][b][c] = 1;
    int ans = 1;

    for(int k = 0; k < 6; k++) {
        int aa = a + mov[k][0];
        int bb = b + mov[k][1];
        int cc = c + mov[k][2];
        if(isIn(aa,bb,cc) and !vis[aa][bb][cc] and mat[aa][bb][cc] == 'x') ans += dfs(aa,bb,cc);
    }
    return ans;
}

void preenche(int a, int b, int c) {
    vis[a][b][c] = 2;
    ans[a][b][c] = f;
    comp[a][b][c] = cont;

    for(int k = 0; k < 6; k++) {
        int aa = a + mov[k][0];
        int bb = b + mov[k][1];
        int cc = c + mov[k][2];
        if(isIn(aa,bb,cc) and vis[aa][bb][cc] == 1 and mat[aa][bb][cc] == 'x') preenche(aa,bb,cc);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin >> x >> y >> z;

    for(int i = 0; i < z; i++)
        for(int j = 0; j < y; j++)
            for(int p = 0; p < x; p++)
                cin >> mat[i][j][p];

    int r = 0;

    for(int i = 0; i < z; i++) {
        for(int j = 0; j < y; j++) {
            for(int p = 0; p < x; p++) {
                if(!vis[i][j][p] and mat[i][j][p] == 'x') {
                    f = dfs(i,j,p);
                    cont++;
                    preenche(i,j,p);
                }
            }
        }
    }

    for(int j = 0; j < y; j++) {
        for(int p = 0; p < x; p++) {
            int at = 0;
            set<int> bag;
            for(int i = 0; i < z; i++) {
                if(!bag.count(comp[i][j][p])) {
                    bag.insert(comp[i][j][p]);
                    at += ans[i][j][p];
                }
            }
            r = max(r,at);
        }
    }
    cout << r << endl;
    return 0;
}

